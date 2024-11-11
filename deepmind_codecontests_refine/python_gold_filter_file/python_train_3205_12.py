N,M=map(int,input().split())
H=list(map(int,input().split()))
t=[1]*N
for i in range(M):
    a,b=map(int,input().split())
    if H[a-1]>H[b-1]:
        t[b-1]=0
    elif H[a-1]<H[b-1]:
        t[a-1]=0
    else:
        t[a-1],t[b-1]=0,0
print(sum(t))