n,k=map(int,input().split())
l=list(map(int,input().split()))
K=min(l)
for i in range(n):
    if (l[i]-K)%k!=0:
        print(-1)
        exit()
Sum=sum(l)
K=K*n
Sum=Sum-K
print(Sum//k)