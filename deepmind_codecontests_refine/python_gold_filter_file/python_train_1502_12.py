import sys
from math import log2,floor,ceil,sqrt,gcd
import bisect
# from collections import deque
sys.setrecursionlimit(10**5)

Ri = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD =  1000000007


def solve(n):
    nob = n*dic.get('B',0)
    noc = n*dic.get('C',0)
    nos = n*dic.get('S',0)
    reqb  = max(nob-b,0)
    reqs  = max(nos-s,0)
    reqc  = max(noc-c,0)
    # if n == 5:
    #     print(reqb*pb + reqs*ps + reqc*pc,r)
    if reqb*pb + reqs*ps + reqc*pc > rr:
        # if n == 5:
        #     print("fsfds")
        return False
    return True
st = ri()
b,s,c = Ri()
pb,ps,pc  = Ri()
rr = int(ri())
dic = {}
for i in range(len(st)):
    if st[i] in dic:
        dic[st[i]]+=1
    else:
        dic[st[i]] = 1

l = 0
r = 10**13
ans = 0
while(l<= r):
    
    mid = (l+r)//2
    # print(mid)
    if(solve(mid)):
        # print(mid)
        ans=max(ans,mid)
        l=mid+1
    else:
        r=mid-1
print(ans)