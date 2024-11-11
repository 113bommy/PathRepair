from math import sqrt
ans = 100000.00
a, b = map(int, input().split())
n = int(input())
for i in range(n):
    x, y, p = map(int, input().split())
    r = ((x-a)**2) + ((y-b)**2)
    if p is not 0:
        r = sqrt(r)/p
        ans = min(r, ans)
print("{:.7f}".format(ans))