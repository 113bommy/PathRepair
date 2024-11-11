S = input()

D = {
    'U': (0, 1),
    'D': (0, -1),
    'L': (-1, 0),
    'R': (1, 0)
}

x = y = 0
for c in S:
    dx, dy = D[c]
    x += dx
    y += dy

if len(S) % 2 == 1:
    print(-1)
else:
    print((abs(min(x, y)) + abs(max(x, y))) // 2)
