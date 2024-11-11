n = int(input())
ans = 1
for i in range(2, n+1):
    ans += 4*i-4
print(ans)