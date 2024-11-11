import math
import time
from collections import defaultdict,deque,Counter
from sys import stdin,stdout
from bisect import bisect_left,bisect_right
from queue import PriorityQueue 
import sys
class Graph:
    def __init__(self, n):
        self.graph = defaultdict(lambda: [])
        self.vertices = n
        self.edges = 0
        self.toposorted = []

    def addEdge(self, a, b):  # tested
        self.graph[a].append(b)
        self.edges+=1

    def cycleUntill(self, visited, curr, parent):  # tested
        visited[curr] = True
        for i in self.graph[curr]:
            if(not visited[i]):
                if(self.cycleUntill(visited, i, curr)):
                    return True
            elif(i != parent):
                return True
        return False

    def cycle(self):  # tested
        n = self.vertices
        visited = [False]*(n+2)
        for i in range(1, n+1):
            if(not visited[i]):
                if(self.cycleUntill(visited, i, -1)):
                    return True
        return False

    def topologicalSort(self):#tested
        in_degree = [0]*(self.vertices+10)
        for i in self.graph:
            for j in self.graph[i]:
                in_degree[j] += 1
        queue = deque()
        for i in range(1,self.vertices+1):
            if in_degree[i] == 0:
                queue.append(i)
        cnt = 0
        while queue:
            u = queue.popleft()
            self.toposorted.append(u)
            for i in self.graph[u]:
                in_degree[i] -= 1
                if in_degree[i] == 0:
                    queue.append(i)
            cnt += 1
        if cnt != self.vertices:
            return False
        else:
            return True
    def connected(self):
        visited=[False]*(self.vertices +2)
        ans=[]
        for i in range(1,self.vertices+1):
            if(not visited[i]):
                comp=[]
                q=deque()
                visited[i]=True
                q.append(i)
                while(len(q)>0):
                    temp=q.popleft()
                    comp.append(temp)
                    for j in self.graph[temp]:
                        if(not visited[j]):
                            visited[j]=True
                            q.append(j)
                ans.append(comp)
        return ans
    

n,m,k=map(int,stdin.readline().split())
a=list(map(int,stdin.readline().split()))
g=Graph(n)
for _ in range(m):
    l,r=map(int,stdin.readline().split())
    g.addEdge(l,r)
    g.addEdge(r,l)
connected=g.connected()
ans=0
# print(connected)
for i in connected:
    color=[0]*len(i)
    for j in range(len(i)):
        color[j]=a[i[j]-1]
    count=Counter(color)
    # print(count,len(i),count.most_common(1)[0][1] )
    ans+=len(i)-count.most_common(1)[0][1] 
print(ans)
    

