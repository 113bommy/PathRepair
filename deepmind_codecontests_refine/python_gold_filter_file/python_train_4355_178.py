n,k=map(int,input().split())
print((n-1)//(k-1)+(1 if (n-1)%(k-1) else 0))