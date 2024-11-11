import heapq
n,k=map(int,input().split())
if n==1 or n==2:
    print('1'*n)
    exit()
arr=list(map(int,input().split()))
ll=[]
q=[]
for i in range(n):
    heapq.heappush(q,(-arr[i],i))
    if i==0:
        ll.append([-1,1])
    elif i==n-1:
        ll.append([n-2,-1])
    else:
        ll.append([i-1,i+1])
ans=[0]*n
s=set()
flag=True
while len(q)!=0:
    val,pos=heapq.heappop(q)
    val*=-1
    if val in s:
        continue
    cnt=0
    pos1=pos
    pos2=pos
    val1=val
    val2=val
    while cnt<=k and pos1!=-1:
        s.add(val1)
        if flag==True:
            ans[pos1]=1
        else:
            ans[pos1]=2
        pos1=ll[pos1][1]
        val1=arr[pos1]
        cnt+=1
    cnt=0
    while cnt<=k and pos2!=-1:
        s.add(val2)
        if flag==True:
            ans[pos2]=1
        else:
            ans[pos2]=2
        pos2=ll[pos2][0]
        val2=arr[pos2]
        cnt+=1
    if pos1!=-1 and pos2!=-1:
        ll[pos1][0]=pos2
        ll[pos2][1]=pos1
    elif pos1==-1 and pos2!=-1:
        ll[pos2][1]=-1
    elif pos1!=-1 and pos2==-1:
        ll[pos1][0]=-1
    if flag==True:
        flag=False
    else:
        flag=True
print(''.join(map(str,ans)))