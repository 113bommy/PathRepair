N, K = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a[:K])
ans = s
for i in range(N-K):
    s = s - a[i] + a[i+K]
    ans = max(s, ans)
print((ans+K)/2)