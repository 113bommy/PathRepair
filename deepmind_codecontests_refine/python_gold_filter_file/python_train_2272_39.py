N, C = map(int,input().split())
D = []
for i in range(C):
    t = list(map(int,input().split()))
    D.append(t)
c = []
for i in range(N):
    t = list(map(int,input().split()))
    c.append(t)
Dsum = []
for k in range(C):
    ccc = [0, 0, 0]
    for i in range(N):
        for j in range(N):
            ccc[(i+j)%3] += D[c[i][j]-1][k]
    Dsum.append(ccc)
ans = 9876543210
for i in range(C):
    for j in range(C):
        for k in range(C):
            if i != j and j != k and k != i:
                ans = min(ans, Dsum[i][0]+Dsum[j][1]+Dsum[k][2])
print(ans)