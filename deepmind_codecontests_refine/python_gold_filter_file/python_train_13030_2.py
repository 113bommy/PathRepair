from sys import setrecursionlimit
from collections import defaultdict
from threading import stack_size,Thread
setrecursionlimit(10**6)
stack_size(2**25)
edge=defaultdict(list)
visited=[False]*(100001)
intime=[0]*(100001)
low=[0]*(100001)
l1=[]
bridge=False
timer=0
def DFS(node,parent):
    global l1,edge,visited,intime,low,timer,bridge
    visited[node]=1
    intime[node]=timer
    low[node]=timer
    timer+=1
    for child in edge[node]:
        if visited[child]==1:
            if child==parent:
                pass
            else:
                low[node]=min(intime[child],low[node])
                if (intime[node]>intime[child]):
                    l1.append([node,child])
        else:
            DFS(child,node)
            if low[child]>intime[node]:
                bridge=True
                return None
            l1.append([node,child])    
            low[node]=min(low[node],low[child])                

def main():
    r=lambda:map(int,input().split())
    n,m=r()
    global edge,visited,intime,low,l1,bridge,timer
    for i in range(1,n+1):
        edge[i]=[]
        visited[i]=0
        intime[i]=0
        low[i]=0
    for _ in range(m):
        p,q=r()
        edge[p].append(q)
        edge[q].append(p)    
    DFS(1,-1)
    if bridge==True:
        print(0)
    else:
        # print(l1)
        for i in l1:
            print(*i)        
if __name__ == "__main__":
    Thread(target=main).start()         


