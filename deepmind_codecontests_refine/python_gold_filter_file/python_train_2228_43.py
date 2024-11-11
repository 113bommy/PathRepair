n,m=map(int,input().split())
#print(n,m)
a=list(int(x) for x in input().split())
a.sort()
max=1000
#print(a)
for i in range(n-1,m):
    #print(a[i]-a[i-n+1])
    if max>a[i]-a[i - n + 1] :
        max=a[i]-a[i-n+1]
print(max)