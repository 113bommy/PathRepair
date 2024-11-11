N = int(input())
P = [list(map(int,input().split())) for k in range(N)]

for h in range(P[0][2],P[0][2]+201):
    for x in range(101):
        for y in range(101):
            f = 1
            for e in P:
                if e[2] != max(0,h-abs(e[0]-x)-abs(e[1]-y)):
                    f = 0
                    break
            if f == 1:
                print(x,y,h)
                exit(0)
