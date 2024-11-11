from collections import deque
N,M=map(int,input().split())
table=[]
#ma=-1
for i in range(M):
    s,t,c=map(int,input().split())
    s,t=s-1,t-1
    table.append((s,t,c))
    #ma=max(c,ma)

def check(k):
    Lin=[0]*N
    edge=[[] for i in range(N)]
    for s,t,c in table:
        if c>k:
            Lin[t]+=1
            edge[s].append(t)
    Haco=deque()
    ans=[]
    for i in range(N):
        if Lin[i]==0:
            ans.append(i)
            Haco.append(i)
    while Haco:
        x = Haco.pop()
        for y in edge[x]:
            Lin[y]-=1
            if Lin[y]==0:
                ans.append(y)
                Haco.append(y)
    return ans
ma=10**9+7
mi=-1
while ma-mi>1:
    mid=(ma+mi)//2
    if len(check(mid))==N:
        ma=mid
    else:
        mi=mid
ans=check(ma)
#print(ma)
#print(ans)
#print(table)
dd={}
for i in ans:
    dd[ans[i]]=i
num=0
answer=[]
#print(dd)
for i in range(M):
    s, t, c=table[i]
    if dd[s]>dd[t] and c<=ma:
        answer.append(i+1)
        num+=1
print(ma,num)
print(' '.join(map(str,answer)))

