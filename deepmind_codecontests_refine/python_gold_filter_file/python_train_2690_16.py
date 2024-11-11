H, W = map(int, input().split())
C = [list(map(int, input().split())) for j in range(10)]
for i in range(10):
    for j in range(10):
        for k in range(10):
            C[j][k] = min(C[j][k], C[j][i] + C[i][k])
 
S = 0
for i in range(H):
    for x in list(map(int, input().split())):
        if x != -1:
            S += C[x][1]
print(S)