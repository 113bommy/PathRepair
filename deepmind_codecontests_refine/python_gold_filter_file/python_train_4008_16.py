n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
print(3*n*min(a[0],a[n]/2,m/n/3))
