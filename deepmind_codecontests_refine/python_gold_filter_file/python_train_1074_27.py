from math import pi

n = int(input())
r = list(map(int, input().split()))
r.sort()
ans = 0

for i in range(n):
    if i&1:
        ans -= r[i]**2*pi
    else:
        ans += r[i]**2*pi

print("%.5f"%abs(ans))
