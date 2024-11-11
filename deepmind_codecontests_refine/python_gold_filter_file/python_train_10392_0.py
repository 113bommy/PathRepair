N = int(input())
point = [tuple(map(int, input().split())) for i in range(N)]
point_farthest = max(point, key=lambda p: abs(p[0]) + abs(p[1]))
mod = sum(point_farthest) % 2
D = [1, 1] if mod == 0 else [1]
while sum(D) < abs(point_farthest[0]) + abs(point_farthest[1]):
    D.append(D[-1] * 2)
D.reverse()
W = []
for x, y in point:
    if (x + y) % 2 != mod:
        print(-1)
        exit()
    w = ''
    for d in D:
        if abs(x) >= abs(y):
            if x > 0:
                w += 'R'
                x -= d
            else:
                w += 'L'
                x += d
        else:
            if y > 0:
                w += 'U'
                y -= d
            else:
                w += 'D'
                y += d
    W.append(w)
print(len(D))
print(*D)
print(*W, sep='\n')