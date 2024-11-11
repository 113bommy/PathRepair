r, g, b = sorted(map(int, input().split()))
ans = 0
for i in range(min(3, r + 1)):
    ans = max(ans, r // 3 + g // 3 + b // 3 + min(r % 3, g % 3, b % 3) + i)
    r -= 1
    g -= 1
    b -= 1
print(ans)
