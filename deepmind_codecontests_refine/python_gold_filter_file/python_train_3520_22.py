N=int(input())
A=list(map(int,input().split()))
a=[0]*(N+1)
for i in range(N):
    a[i+1]=a[i]+A[i]
d=[[0]*(N+1) for i in range(N+1)]
for w in range(2,N+1):
    for l in range(N+1-w):
        d[l][l+w]=min([d[l][m]+d[m][l+w] for m in range(l+1,l+w)])+a[l+w]-a[l]
print(d[0][N])