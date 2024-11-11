N, K = map(int, input().split())
ans = 0
for i in range(K, N+2):
    ans += (N-i+1)*i + 1
print(ans%(10**9+7))