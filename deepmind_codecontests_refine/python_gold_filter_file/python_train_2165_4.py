n=int(input())
l=list(map(int,input().split()))
t=1
ans=0
for i in l:
    if i==t:
        t+=1
    else:
        ans+=1
if t==1:
    ans=-1
print(ans)