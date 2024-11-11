n,m=map(int,input().split())
l=list(map(int,input().split()))
d=-13546789
for i in range(0,n-1,1):
    if -l[i+1]+l[i]>=d:
        d=-l[i+1]+l[i]
if d-m>0:
    print(d-m)
else:
    print(0)
