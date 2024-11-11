S=str(input())
T=str(input())

ls=len(S)
lt=len(T)


DP=[[0]*(lt+1) for _ in range(ls+1)]


for i in range(1,ls+1):
    for j in range(1,lt+1):
        if S[i-1]==T[j-1]:
            DP[i][j]=max(DP[i-1][j-1]+1,DP[i][j-1],DP[i-1][j])
        else:
            DP[i][j]=max(DP[i][j-1],DP[i-1][j])

lf=DP[ls][lt]

res=''
u=ls
v=lt
while u>0 and v>0:
    if DP[u][v]==DP[u-1][v]:
        u-=1
    elif DP[u][v]==DP[u][v-1]:
        v-=1
    else:
        res=S[u-1]+res
        u-=1
        v-=1

print(res)