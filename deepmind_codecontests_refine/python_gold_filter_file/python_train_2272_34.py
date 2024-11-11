N,C = map(int,input().split())
D = [list(map(int,input().split())) for _ in range(C)]
c = [list(map(int,input().split())) for _ in range(N)]

cst = [[0,0,0] for i in range(C)]

for clr in range(1,C+1):
    for i in range(N):
        for j in range(N):
            cst[clr-1][(i+j+2)%3] += D[c[i][j]-1][clr-1]

ans = 10**10

for i in range(C):
    for j in range(C):
        for k in range(C):
            if i == j or i == k or j == k:
                continue
            ans = min(ans,cst[i][0]+cst[j][1]+cst[k][2])

print(ans)
