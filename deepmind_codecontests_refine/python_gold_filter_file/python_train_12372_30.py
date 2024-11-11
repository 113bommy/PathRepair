import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
MOD = 10**9 + 7

N = int(input())
INF = 10**10
cost = [[INF]*N for _ in range(N)]

for i in range(N):
    C = list(map(int, input().split()))
    for j in range(N):
        cost[i][j] = C[j]
    cost[i][i] = INF

ans = 0
for j in range(N):
    for k in range(j+1,N):
        mn = INF
        for i in range(N):
            mn = min(mn, cost[j][i]+cost[i][k])    
        if (cost[j][k] > mn):
            print (-1)
            exit()
        elif (cost[j][k] < mn):
            ans += cost[j][k]                      
print (ans)