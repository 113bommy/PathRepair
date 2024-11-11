mod = 10**9+7
n, k = map(int, input().split())

ans = 0

for i in range(k, n+1):
    ans += i*(n-i+1)+1

print(ans%mod+1)


