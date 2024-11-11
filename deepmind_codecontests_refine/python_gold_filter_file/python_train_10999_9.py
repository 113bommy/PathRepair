n = int(input())
a = []
for i in range(1, n + 1):
    l, r = map(int, input().split())
    a.append((l, -r, i))
a.sort()
x = a[0][1]
d = a[0][2]
r = [-1] * 2
for i in range(1, n):
    if a[i][1] >= x:
        r = [a[i][2], d]
        break
    else:
        x = a[i][1]
        d = a[i][2]
print(*r)
