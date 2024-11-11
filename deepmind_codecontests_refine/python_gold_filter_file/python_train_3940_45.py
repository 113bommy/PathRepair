n = int(input())
k = int(input())
ans = 1
for i in range(n):
    ans += min(ans, k)
print(ans)