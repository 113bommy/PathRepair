import sys
input = sys.stdin.readline
n,k = map(int,input().split())
edge = [[] for i in range(n)]
alledge = []
for i in range(n-1):
    a,b = map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
    alledge.append((a-1,b-1))

def f(x,y,c):
    global tmp
    c += 1
    for e in edge[x]:
        if e == y:
            continue
        if c > d:
            tmp +=1
        f(e,x,c)

sys.setrecursionlimit(4100000)

if k % 2 == 0:
    d = k//2
    ass = 2001
    for i in range(n):
        tmp = 0
        f(i,-1,0)
        ass = min(ass,tmp)
    print(ass)
else:
    d = (k-1)//2
    ass = 2001
    for e1 in alledge:
        tmp = 0
        f(e1[0],e1[1],0)
        f(e1[1],e1[0],0)
        ass = min(ass,tmp)
    print(ass)
