from heapq import *
pq=[]
ans=[]
a=int(input())
for i in range(a):
    x,y=map(int,input().split())
    ans.append([x,y,i+1])
temp=ans.copy()
ans.sort()
s=int(input())

z=list(map(int,input().split()))
t1=[]
for i in range(len(z)):
    t1.append([z[i],i+1])
t1.sort()
fin=[]
cnt=0
total=0
for i in range(len(t1)):
    while(cnt<len(ans) and ans[cnt][0]<=t1[i][0]):
        heappush(pq,(-ans[cnt][1],ans[cnt][2]))
        cnt+=1
    
    if(len(pq)):
        r=heappop(pq)
        
        fin.append([r[1],t1[i][1]])
        total+=temp[r[1]-1][1]
print(len(fin),total)
for i in range(len(fin)):
    print(fin[i][0],fin[i][1])
    
