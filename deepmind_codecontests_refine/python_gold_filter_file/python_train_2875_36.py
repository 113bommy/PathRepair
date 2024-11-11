n,k=map(int,input().split())
mini = min(1,k,n-k)
maxi = min(n-k,2*k)
print(mini,maxi)