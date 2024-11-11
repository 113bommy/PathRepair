n, m = map(int, input().split())
red = [0]*n
ball = [1]*n
red[0] = 1
for i in range(m):
    x, y = map(int, input().split())
    if red[x-1] == 1:
        red[y-1] = 1
        if ball[x-1] == 1:
            red[x-1] = 0
    ball[y-1] += 1
    ball[x-1] -= 1
print(sum(red))
