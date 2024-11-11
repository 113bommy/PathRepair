n=int(input())
a=[int(i) for i in input().split()]
mind=999999
ans=(0,0)
for i in range(0,len(a)-1):
    mind=min(mind,abs(a[i]-a[i+1]))
mind=min(mind,abs(a[n-1]-a[0]))
for i in range(0,len(a)-1):
    if(abs(a[i]-a[i+1])==mind):
        ans=(i,i+1)
if(abs(a[n-1]-a[0])==mind):
    ans=(0,n-1)
print(ans[0]+1,ans[1]+1)