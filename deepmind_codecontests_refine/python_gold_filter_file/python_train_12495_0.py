#Input
n,m,l = map(int,input().split())
A = [list(map(int,input().split())) for i in range(n)]
B = [list(map(int,input().split())) for i in range(m)]

c = [list(sum([A[i][k] * B[k][j] for k in range(m)]) for j in range(l)) for i in range(n)]

#Output
for i in c:
    print(*i)