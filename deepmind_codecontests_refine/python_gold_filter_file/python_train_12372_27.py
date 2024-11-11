N = int(input())
A = [list(map(int,input().split())) for _ in range(N)]

INF = 10**10
E_list = []
for i in range(N):
    for j in range(i+1,N):
        E_list.append([A[i][j],i,j])
E_list.sort()
B = [[INF]*N for _ in range(N)]
ans = 0
for l,i,j in E_list:
    l_min = INF
    for k in range(N):
        l_min = min(l_min,B[i][k]+B[k][j])
    if l > l_min:
        ans = -1
        break
    elif l < l_min:
        ans += l
    B[i][j] = l
    B[j][i] = l
print(ans)