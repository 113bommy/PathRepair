n,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
r=l[n-1]-l[0]
for i in range(1,m-n+1):
    r=min(r,l[i+n-1]-l[i])
print(r)