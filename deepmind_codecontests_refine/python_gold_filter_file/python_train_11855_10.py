N, M = map(int, input().split())

B = [1]*N
R=[False]*N

R[0]=True

for i in range(M):
    x, y = map(int, input().split())
    x-=1
    y-=1
    if R[x] == True:
        R[y] = True
    B[x] -= 1
    B[y] += 1
    if B[x] == 0:
        R[x] = False

print(sum(R))
