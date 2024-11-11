from collections import defaultdict,deque
import sys
input=sys.stdin.readline
#only possible when there are no cycles of odd length
def bfs(root):
    visited[root]=0
    parity=[1,0]
    store=[[root],[]]
    queue=deque([root])
    while queue:
        vertex=queue.popleft()
        for child in graph[vertex]:
            if visited[child]==-1:
                visited[child]=visited[vertex]^1
                store[visited[child]].append(child)
                queue.append(child)
                parity[visited[child]]+=1
            elif visited[child]==visited[vertex]:
                return(False,(-1,-1),(-1,-1))
    return(True,parity,store)
            
n,m=map(int,input().split())
n1,n2,n3=map(int,input().split())                
graph=defaultdict(list)
for i in range(m):
    u,v=map(int,input().split())
    u-=1
    v-=1
    graph[u].append(v)
    graph[v].append(u)
visited=[-1]*(n)
ans=[]
ind=[]
for i in range(n):
    if visited[i]==-1:
        ret,ret2,ret3=bfs(i)
        if not ret:
            print('NO')
            exit()
        ind.append(ret3)
        ans.append(ret2)
#dp required to know which partition(odd or even) of each connected component we
#have to assign 2 in order for the total number of nodes with value 2 to become
#equal to 2
dp=[[False]*(n+1) for _ in range(len(ans)+1)]
dp[0][0]=True
#for the dp read editorial
for i in range(len(ans)):
    #print(ans)
    even,odd=ans[i][0],ans[i][1]
    for j in range(len(dp[0])):
        if even+j<(n+1):
            dp[i+1][j+even]=(dp[i][j] or dp[i+1][j+even])
        if odd+j<(n+1):
            dp[i+1][j+odd]=(dp[i][j] or dp[i+1][j+odd])
        
            
#print(dp,ind)
if dp[-1][n2]==False:
    print("NO")
    exit()
c = n2
which = set()
#gives the parity(odd or even) of each connected component of whose
#indices we have to assign 2
for i in range(len(dp)-1,0,-1):
    if dp[i][c]==True:
        for j, val in enumerate(ans[i-1]):
            #while n2 nodes are not yet assigned 2, carry on
            if c - val >= 0:
            #some node cn only be assigned 2 if dp[i-1][c-val]==True
                if dp[i-1][c - val]:
                    c = c - val
                    which.update(ind[i-1][j])
                    break

outp=[]
count=0
for i in range(n):
    if i in which:
        outp.append(2)
    else:
        if count<n1:
            outp.append(1)
            count+=1
        else:
            outp.append(3)
print("YES")
print("".join(map(str, outp)))
    
    
            


          
          
               
     
