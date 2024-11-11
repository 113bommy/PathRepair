N = int(input())
K = int(input())

ans = 1
for _ in range(N):
  ans = min(2*ans, ans+K)
print(ans)