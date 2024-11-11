from sys import stdin, stdout
from math import *
from heapq import *
from collections import *
n,m,k,a=0,0,0,0
edge=[]
def bfs(root):
    global n,m,k,a,edge
    d=[-1 for u in range(n+1)]
    d[root]=0
    q=[root]
    i=0
    while(i<len(q)):
        u=q[i]
        for v in edge[u]:
            if (d[v]==-1):
                d[v]=d[u]+1
                q.append(v)
        i=i+1
    return d
def main():
    global n,m,k,a,edge
    n,m,k=[int(x) for x in stdin.readline().split()]
    a=[int(x) for x in stdin.readline().split()]
    edge=[set() for i in range(n+1)]
    for i in range(m):
        x,y=[int(x) for x in stdin.readline().split()]
        edge[x].add(y)
        edge[y].add(x)
    f1=bfs(1)
    fn=bfs(n)
    sp1=[]
    res1=f1[n]
    res2=-1
    sp2=[]
    for u in a:
        if (f1[u]>=0):
            sp1.append((u,f1[u]))
        if (fn[u]>=0):
            sp2.append((u,fn[u]))
    sp1.sort(key=(lambda p: -p[1]))
    sp2.sort(key=(lambda p: -p[1]))
    for ind in range(len(sp1)-1):
        v,dv=sp1[ind]
        u,du = sp1[ind+1]
        if (v!=u):
            res2=max(res2, min(fn[v]+1+f1[u],fn[u]+f1[v]+1))
        v,dv=sp2[ind]
        u,du = sp2[ind+1]
        if (v!=u):
            res2=max(res2, min(fn[v]+1+f1[u],fn[u]+f1[v]+1))
    stdout.write("%d"%(min(res1,res2)))
    return 0

if __name__ == "__main__":
    main()