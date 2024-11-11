ans = 0
n,m = map(int,input().split())
dis = [[float('inf') for i in range(n)] for j in range(n)] #各点距離を最初∞に設定
abt = []
for i in range(m):
    abt.append(list(map(int,input().split()))) #入力
for a,b,t in abt:
    dis[a-1][b-1] = t #頂点aからbへの距離がt
    dis[b-1][a-1] = t # 逆も同様
for i in range(n):
    for j in range(n):
        for k in range(n):
            dis[k][j] = min(dis[k][j], dis[k][i] + dis[i][j])
for a,b,t in abt:
    if t > dis[a-1][b-1]:
        ans +=1
print(ans)