N = int(input())
K = int(input())
ans = 1
for i in range(N):
  ans += min(ans, K)
print(ans)  