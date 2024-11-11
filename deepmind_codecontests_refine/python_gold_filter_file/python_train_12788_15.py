A,B,C,D,E,F = map(int,input().split())

xy = []
for Ai in range(0,F+1,100*A):
    for Bj in range(0,F-Ai+1,100*B):
        x = Ai + Bj
        for Ci in range(0,(F-x)+1,C):
            Dj = 0
            y = Ci + Dj
            while x + y <= F:
                xy.append((x,y))
                Dj += D
                y += D

ans = (100*A,0)
node = 0
for x,y in xy:
    if x == y == 0:
        continue
    if (x//100) * E >= y:
        tmp = 100*y/(x+y)
        if node < tmp:
            ans = (x+y, y)
            node = tmp

print(*ans)