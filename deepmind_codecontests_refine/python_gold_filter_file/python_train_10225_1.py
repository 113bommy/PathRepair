from collections import defaultdict
n,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
d1=defaultdict(lambda: "safal")
d2=[]
result=[]
ans=0
for i in range(n):
    d1[l[i]]=0
    d2.append(l[i])
t=0
while(len(d2)!=t):
    if(len(result)==m):
        break
    cur=d2[t]
    t+=1

    if(d1[cur]!=0 and d1[cur]!="safal"):
        ans+=d1[cur]
        result.append(cur)
    if(d1[cur-1]=="safal"):
        d1[cur-1]=d1[cur]+1
        d2.append(cur-1)
    if(d1[cur+1]=="safal"):
        d1[cur+1]=d1[cur]+1
        d2.append(cur+1)
print(ans)
for i in result:
    print(i,end=" ")
