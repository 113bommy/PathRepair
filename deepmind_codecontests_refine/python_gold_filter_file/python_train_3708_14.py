n, p, q, r = map(int, input().split())
ar = list(map(int, input().split()))
su = r * ar[-1]
suf = [0] * n
for i in range(n-1, -1, -1):
    su = suf[i] = max(r * ar[i], su)
pr = p * ar[0]
ans = -1111111111111111111111111111
for i in range(n):
    pr = max(pr, p * ar[i])
    ans = max(ans, pr + q * ar[i] + suf[i])
print(ans)