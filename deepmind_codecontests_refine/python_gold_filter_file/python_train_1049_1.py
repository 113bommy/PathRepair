
import sys
n,d,k=map(int,input().split())
if(n<=d):
    print('NO')
    sys.exit()
if(k==1 and n>2):
    print('NO')
    sys.exit()

edgestot=[]
edges=[[] for i in range(n)]
tovisit=[]
for i in range(d):
    edgestot.append([i,i+1])
    tovisit.append([i+1,min(i+1,d-i-1)])
    edges[i].append(i+1)
    edges[i+1].append(i)
cur=d+1
while(cur<n and len(tovisit)>0):
    x=tovisit.pop()
    if(x[1]==0):
        continue
    while(len(edges[x[0]])<k and cur<n):
        tovisit.append([cur,x[1]-1])
        edgestot.append([cur,x[0]])
        edges[x[0]].append(cur)
        edges[cur].append(x[0])
        cur+=1

#print(edgestot)
if(len(edgestot)==n-1):
    print('YES')
    for i in range(n-1):
        print(edgestot[i][0]+1,edgestot[i][1]+1)
    
else:
    print('NO')
