import sys
N,M=map(int,input().split())
data=[[0]*(N+1) for i in range(N+1)]
for i in range(M):
    A,B=map(int,input().split())
    data[A][B]=1
    data[B][A]=1
for i in range(1,N+1):
    data[i][i]=1
lst=[-1]*(N+1)
ddd=[]
for i in range(1,N+1):
    if lst[i]!=-1:
        continue
    else:
        lst[i]=0
        que=[i]
        count=[1,0]
        while que:
            h=[]
            for u in que:
                for j in range(1,N+1):
                    if data[u][j]==1:
                        continue
                    else:
                        if lst[j]==-1:
                            lst[j]=lst[u]^1
                            count[lst[j]]+=1
                            h.append(j)
                        elif lst[j]^lst[u]==0:
                            print(-1)
                            sys.exit()
            que=h
        ddd.append(count)
dp=[0]*(N+1)
dp[0]=1
for u in ddd:
    v=u[0]
    h=[0]*(N+1)
    for i in range(v,N+1):
        if dp[i-v]==1:
            h[i]=1
    v=u[1]
    for i in range(v,N+1):
        if dp[i-v]==1:
            h[i]=1
    dp=h
ans=0
for i in range(N+1):
    if dp[i]==1:
        if abs(N-2*ans)>abs(N-2*i):
            ans=i
qqq=N-ans
if qqq==0 or ans==0:
    print(N*(N-1)//2)
else:
    print(ans*(ans-1)//2+qqq*(qqq-1)//2)