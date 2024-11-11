x, y = map(int, input().split())
ans = 0
if x <= 3:
    ans += 400000 - x * 100000
if y <= 3:
    ans += 400000 - y * 100000
if x == y == 1:
    ans += 400000
print(ans)
