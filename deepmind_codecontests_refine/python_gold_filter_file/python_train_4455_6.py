n,k=map(int,input().split())
print(sum(-~i+i*(n-i)for i in range(k,n+2))%(10**9+7))