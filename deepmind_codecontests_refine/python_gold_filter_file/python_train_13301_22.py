R, C, K = map(int,input().split())
V = [[]for i in range(R)]
for i in range(K):
    r,c,v = map(int,input().split())
    V[r-1].append([c,v])
cost = [0]*(C+1)
for r in range(R):
    V[r].sort()
    hoge = [0,0,0,0]
    for c,v in V[r]:
        for i in range(3,0,-1):
            hoge[i] = max(cost[c]+v,hoge[i-1]+v,hoge[i])
        hoge[0] = cost[c]
        cost[c] = max(hoge)
    for i in range(1,C+1):
        cost[i] = max(cost[i],cost[i-1])

print(cost[-1]) 