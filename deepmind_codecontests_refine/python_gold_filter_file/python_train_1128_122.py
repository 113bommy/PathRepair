N = int(input())
a = [int(x) for x in input().split()]

b = [0]*9
ans = 0
count = 0
for i in a:
    if i//400 < 8:
        b[i//400] = 1
    else:
        b[8] += 1
print(max(1, sum(b[:8])), sum(b))
