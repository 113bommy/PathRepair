n,k=map(int,input().split())
print(((n*(n+1)*(n+2)-(3*n-2*k+4)*(k-1)*k)//6-k+n+2)%(10**9+7))