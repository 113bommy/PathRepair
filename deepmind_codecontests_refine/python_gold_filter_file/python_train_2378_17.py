from collections import deque
N,M=map(int,input().split())
Table=[[] for i in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    Table[a-1].append(b-1)
    Table[b-1].append(a-1)
visit=[False]*N
iro=[-1]*N
kei=deque()
def nibu():
    kei.append(0)
    iro[0]=0
    while kei:
        x = kei.pop()
        visit[x]=True
        for i in Table[x]:
            if visit[i] and iro[i] == iro[x]:
                return False
            elif not visit[i]:
                kei.append(i)
                iro[i]=(iro[x]+1)%2
    return True
if nibu():
    B = iro.count(0)
    W = iro.count(1)
    ans = B*W-M
else:
    ans = (N*(N-1))//2 -M
print(ans)