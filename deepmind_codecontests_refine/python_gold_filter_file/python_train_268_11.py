n, k, m = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
s = sum(l)

ans = 0
for i in range(n + 1):
    mi = m - s * i
    if mi < 0:
        break
    cnt = (k + 1) * i
    for j in range(k):
        x = min(mi // l[j], n - i)
        cnt += x
        mi -= l[j] * x
    ans = max(ans, cnt)
print(ans)
