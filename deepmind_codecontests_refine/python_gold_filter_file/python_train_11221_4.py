H,N=map(int,input().split())
M=[tuple(map(int,input().split())) for i in range(N)]

D=[1<<31]*(H+10**4)
D[0]=0

for hp in range(H):
    for a,b in M:
        D[hp+a]=min(D[hp+a],D[hp]+b)
print(min(D[H:]))
