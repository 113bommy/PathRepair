N,M,X=map(int,input().split())
l=[list(map(int,input().split())) for i in range(N)]


cmin=12*10**5+1
for bit in range(2**N):
    A=[0]*M
    c=0
    for j in range(N):
        if (bit>>j)&1:
            c+=l[j][0]
            A=[x+y for (x,y) in zip(A, l[j][1:])]
    if min(A) >= X:
        cmin=min(cmin,c)

if cmin!=12*10**5+1:
    print(cmin)
else:
    print(-1)