h, w = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]
move = []
for i in range(h):
    for j in range(w):
        if a[i][j] % 2 == 1:
            if j+1 < w:
                a[i][j+1] += 1
                move.append((i,j,i,j+1))
            elif i+1 < h:
                a[i+1][j] += 1
                move.append((i,j,i+1,j))
print(len(move))
for x, y, xp, yp in move:
    print(x+1,y+1,xp+1,yp+1)
