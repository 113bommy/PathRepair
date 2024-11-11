N,C = map(int,input().split())
D=[[int(i) for i in input().split()] for j in range(C)]
co=[[int(i) for i in input().split()] for j in range(N)]
A=[[0]*C for i in range(3)]#iに変えた時の違和感
for i in range(N):
    for j in range(N):
        t = (i+j)%3
        for s in range(C):
            A[t][s]+=D[co[j][i]-1][s]
ans =10**13
for x in range(C):
    for y in range(C):
        if x==y:
            continue
        for z in range(C):
            if x==z or y==z:
                continue
            ans=min(ans,A[0][x]+A[1][y]+A[2][z])
print(ans)