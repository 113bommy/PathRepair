n,m,d=map(int,input().split())
print((n+max(0,n-d*2))/n/n*(m-1) if d>0 else 1/n*(m-1))