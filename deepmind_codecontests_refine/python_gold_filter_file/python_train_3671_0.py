import sys

input=sys.stdin.readline

for _ in range(int(input())):
    n,k=map(int,input().split())
    edge=[[] for i in range(n)]
    for i in range(n-1):
        x,y=map(int,input().split())
        edge[x-1].append(y-1)
        edge[y-1].append(x-1)
    leaf=[[] for i in range(n)]
    for i in range(n):
        if len(edge[i])==1:
            leaf[edge[i][0]].append(i)

    #print(leaf)

    que=[i for i in range(n) if len(leaf[i])>=k]
    #print(que)
    deg=[len(edge[i]) for i in range(n)]
    delete=set([])
    ans=0
    while que:
        v=que.pop()
        if v in delete:
            continue
        q=len(leaf[v])//k
        count=q*k
        ans+=q
        while count:
            dv=leaf[v].pop()
            delete.add(dv)
            count-=1
        deg[v]-=q*k
        if deg[v]==1:
            for nv in edge[v]:
                if nv not in delete:
                    leaf[nv].append(v)
                    if len(leaf[nv])==k:
                        que.append(nv)
                    break
    print(ans)
    #print("ans:{}".format(ans))
