N = int(input())
L = [list(map(int, input().split())) for k in range(N)]
m = 0
for l in L:
    m = max(m,l[2])

for x in range(101):
    for y in range(101):
        for h in range(m,m+101):
            f = 1
            for l in L:
                if l[2]!=max(h-abs(l[0]-x)-abs(l[1]-y),0):
                    f = 0
                    break
            if f:
                print(x,y,h)
                exit(0)