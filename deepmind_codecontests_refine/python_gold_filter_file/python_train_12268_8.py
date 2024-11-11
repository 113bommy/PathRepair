import sys
n = int(input())
d = {}
for i in input().split():
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

m = int(input())
for i in input().split():
    if i in d and d[i] > 0:
        d[i] -= 1
    else:
        print("NO")
        sys.exit()
print("YES")
