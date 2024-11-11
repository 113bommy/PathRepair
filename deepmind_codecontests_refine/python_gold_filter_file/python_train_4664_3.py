X, Y = map(int, input().split())

ans = 0
if X < 4:
    ans += (4 - X) * 10**5

if Y < 4:
    ans += (4 - Y) * 10**5

if X == 1 and Y == 1:
    ans += 4 * 10**5

print(ans)