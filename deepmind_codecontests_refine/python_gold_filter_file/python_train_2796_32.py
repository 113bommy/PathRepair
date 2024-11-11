N,x=map(int,input().split())
if x==1 or x==2*N-1:
    print("No")
    exit()
if N==2:
    print('Yes')
    print(*[1,2,3],sep='\n')
    exit()
s=set(range(1,2*N))
s.remove(x)
ans=[0]*(2*N-1)
ans[N-1]=x
min1=min(s)
max1=max(s)
s.remove(min1);s.remove(max1)
if x==2*N-2:
    min2=min(s)
    s.remove(min2)
    ans[N-2]=min1;ans[N]=max1;ans[N+1]=min2
else:
    max2=max(s)
    s.remove(max2)
    ans[N-2]=max1;ans[N]=min1;ans[N+1]=max2
li=list(s)
for i in range(2*N-1):
    if ans[i]==0:
        ans[i]=li.pop()
print("Yes")
print(*ans,sep='\n')