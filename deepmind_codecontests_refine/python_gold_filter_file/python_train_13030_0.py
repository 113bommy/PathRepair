from sys import stdin,setrecursionlimit
import threading
input = lambda: stdin.readline().rstrip("\r\n")
#from collections import defaultdict as vector
from collections import deque as que
inin = lambda: int(input())
inar = lambda: list(map(int,input().split()))


from collections import defaultdict
adj=defaultdict(list)
visited=[False]*(100001)
intime=[0]*(100001)
outtime=[0]*(100001)
res=[]
bridge=False
timer=0
def dfs(node,par):
    global adj, visited, intime, outtime, res, bridge,timer
    visited[node]=True
    intime[node]=timer
    outtime[node]=timer
    timer+=1
    for j in adj[node]:
        if j==par:
            continue
        if visited[j]:
            outtime[node]=min(outtime[node],intime[j])
            if intime[node]>intime[j]:
                res.append((node,j))
        else:
            dfs(j,node)
            if outtime[j]>intime[node]:
                bridge=True
                return
 
            res.append((node,j))
            outtime[node] = min(outtime[node], outtime[j])
def main():
    n,m=map(int,input().split())
    global adj,visited,intime,outtime,res,bridge,timer
    timer=0
    bridge=False
    for i in range(m):
        u,v=map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)
    dfs(1,-1)
    if bridge:
        print(0)
    else:
        for i in range(len(res)):
            print(*res[i])



setrecursionlimit(1 << 30)
threading.stack_size(1 << 25)
main_thread = threading.Thread(target=main)
main_thread.start()
main_thread.join()