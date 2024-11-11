def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(input())
def S(): return input()
n,k=IL()
top=dict()
sub=[]
for i in range(n):
    t,d=IL()
    if t in top:
        sub.append(min(top[t],d))
        top[t]=max(top[t],d)
    else:
        top[t]=d

top=sorted(top.items(),key=lambda x:-x[1])
sub.sort(reverse=True)

rtop=[top[0][1]]
rsub=[0]
for i in range(1,len(top)):
    rtop.append(rtop[-1]+top[i][1])
for i in range(len(sub)):
    rsub.append(rsub[-1]+sub[i])

ans=0
for i in range(k):
    if i<len(rtop) and 0<=k-i-1<len(rsub):
        ans=max(ans,rtop[i]+rsub[k-i-1]+(i+1)**2)
print(ans)