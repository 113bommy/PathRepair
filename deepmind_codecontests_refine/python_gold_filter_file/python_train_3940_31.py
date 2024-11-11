N = int(input())
K = int(input())
ans = 1
for k in range(N):
    ans = min(ans*2, ans+K)
print(ans)