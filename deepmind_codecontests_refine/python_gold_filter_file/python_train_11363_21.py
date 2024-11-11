a = int(input())
ans = 0
for i in range(a - 2):
    ans += (i + 2) * (i + 3)
print(ans)