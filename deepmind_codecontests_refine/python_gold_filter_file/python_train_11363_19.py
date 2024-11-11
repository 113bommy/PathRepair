n = int(input())
ans = 0
for i in range(n - 2):
    ans += (i + 2) * (i + 3)
print(ans)