import sys
sys.setrecursionlimit(1000000)

n,m=map(int,input().split())

#初期値が0の辞書
from collections import defaultdict
xyz = defaultdict(lambda: set([]))
for _ in range(m):
    x,y,z=map(int,input().split())
    xyz[x].add(y)
    xyz[y].add(x)

no_checked=[0]*n

def DFS(x):
    global no_checked
    global xyz
    no_checked[x-1]=1
    for item in xyz[x]:
        if no_checked[item-1]==0:
            DFS(item)

cnt=0
for i in range(1,n+1):
    if no_checked[i-1]==0:
        cnt+=1
        DFS(i)

    #print(i,no_checked)
print(cnt)

