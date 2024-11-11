from math import ceil,sqrt
def prime():
    l = [0]*100001
    n = 100001
    l[0] = 2
    l[1] = 2
    l[2] = 2
    l[n-1] = 100003
    for i in range(n-2,2,-1):
        flag = True
        for j in range(2,ceil(sqrt(i)+1)):
            if i%j==0:
                flag = False
                break
        if flag:
            l[i] = i
        else:
            l[i] = l[i+1]
    return l
pri = prime()
n,m = map(int,input().split())
mat = list()
for i in range(n):
    mat.append(list(map(int,input().split())))
near = [[0 for i in range(m)]for j in range(n)]
for i in range(n):
    for j in range(m):
        near[i][j] = abs(mat[i][j] - pri[mat[i][j]])
k = float('inf')

for i in range(n):
    tmp = 0
    for j in range(m):
        tmp += near[i][j]
    k = min(tmp,k)

for i in range(m):
    tmp = 0
    for j in range(n):
        tmp += near[j][i]
    k = min(tmp,k)
print(k)