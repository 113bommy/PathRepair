def examA():
    S = SI(); N = len(S)
    prev = S[0]; cur = ""
    k = 0; ans = 1
    while(k<N-1):
        k +=1
        cur += S[k]
        if cur==prev:
            continue
        prev = cur
        cur = ""
        ans +=1
    print(ans)
    return

def examB():
    N = I()
    S = SI()
    return

def examC():
    N = I()
    A = LI()
    B = LI()
    ans = 0
    que = []
    for i in range(N):
        heappush(que,(-B[i],i))
    flag = True
    while(que):
        b,i = heappop(que)
        b *=(-1)
        if b == A[i]:
            continue
        a, c = B[(i - 1) % N], B[(i + 1) % N]
        if b - A[i] < a + c:
            flag = False
            break
        r = (b - A[i]) // (a + c)
        b -= (a + c) * r
        B[i] = b
        ans += r
        if b != A[i]:
            heapq.heappush(que, (-b, i))
#    print(que)
#    print(K)
    if flag:
        print(ans)
    else:
        print(-1)
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18

if __name__ == '__main__':
    examC()
