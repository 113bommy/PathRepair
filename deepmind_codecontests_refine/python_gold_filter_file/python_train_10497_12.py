n,k=map(int,input().split())
l=[input().split() for _ in range(n)]
w=[[0]*(k+1) for _ in range(k+1)]
b=[[0]*(k+1) for _ in range(k+1)]
for i in range(n):
    if ((int(l[i][0])//k+int(l[i][1])//k)%2==0)^(l[i][2]=='W'):
        b[int(l[i][0])%k][int(l[i][1])%k]+=1
    else:
        w[int(l[i][0])%k][int(l[i][1])%k]+=1

for i in range(1,k+1):
    b[0][i]+=b[0][i-1]
    b[i][0]+=b[i-1][0]
    w[0][i]+=w[0][i-1]
    w[i][0]+=w[i-1][0]
for i in range(1,k+1):
    for j in range(1,k+1):
        b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1]
        w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1]

ans=0
for i in range(k+1):
    for j in range(k+1):
        ans=max(ans,b[k][k]-b[i][k]-b[k][j]+2*b[i][j]+w[i][k]+w[k][j]-2*w[i][j])
        ans=max(ans,w[k][k]-w[i][k]-w[k][j]+2*w[i][j]+b[i][k]+b[k][j]-2*b[i][j])
print(ans)
