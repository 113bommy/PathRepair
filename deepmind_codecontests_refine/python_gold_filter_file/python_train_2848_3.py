n,k =map(int,input().split())
l=list(map(int,input().split()))
el=l[k-1]
ans=False
for i in range(k,n):
    if(l[i]!=el):
        ans=True
        break
if(ans==True):
    print(-1)
else:
    val=k-1
    for i in range(k-1,0,-1):
        if(l[i]==l[i-1]):
            val=i-1
        else:
            break
    print(val) 