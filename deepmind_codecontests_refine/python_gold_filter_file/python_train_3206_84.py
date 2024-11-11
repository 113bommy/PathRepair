a,b,k=map(int,input().split())
t=max(0,a-k)
ao=max(0,(b if a>=k else b-(k-a)))
print(t,ao)