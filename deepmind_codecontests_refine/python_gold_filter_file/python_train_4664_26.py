X, Y = map(int, input().split())
ans = 0
k = [3, 2, 1]
if X <= 3:
    ans += k[X-1]
if Y <= 3:
    ans += k[Y-1]
if X == 1 and Y == 1:
    ans += 4
print(ans * 100000)