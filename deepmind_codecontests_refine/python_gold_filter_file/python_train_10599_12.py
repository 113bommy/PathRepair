from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(input().split())

N,K = inpl()
aa = [inpl() for _ in range(N)]

def Matdot(A,B):
    C = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k]*B[k][j]
            C[i][j] %= mod
    return C

def power(aa,k):
    if k == 1:
        return aa
    elif k%2 == 0:
        tmp = power(aa,k//2)
        return Matdot(tmp,tmp)
    else:
        tmp = power(aa,(k-1)//2)
        return Matdot(Matdot(tmp,tmp),aa)


aa =  power(aa,K)
ans = 0
for a in aa:
    ans += sum(a)
    ans %= mod
print(ans)
