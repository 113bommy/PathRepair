from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
xx = inpl()
L = int(input())

K = N.bit_length()
db_r = [[0]*K for i in range(N)]
for i,x in enumerate(xx):
    ind = bisect.bisect_right(xx,x+L)
    db_r[i][0] = ind-1

for k in range(1,K):
    for i in range(N):
        db_r[i][k] = db_r[db_r[i][k-1]][k-1]

def check(a,b,d):
    L = d.bit_length()
    for k in range(L):
        if d & (1<<k):
            a = db_r[a][k]
    return a >= b

Q = int(input())
for i in range(Q):
    a,b = inpl()
    a -= 1
    b -= 1
    a,b = min(a,b),max(a,b)
    OK = N
    NG = 0
    while OK-NG>1:
        mid = (OK+NG)//2
        if check(a,b,mid): OK = mid
        else: NG = mid
    print(OK)
