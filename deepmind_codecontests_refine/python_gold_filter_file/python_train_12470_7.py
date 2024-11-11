import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

class Store:
    def __init__(self,a,b):
        self.a=a
        self.b=b

    def __eq__(self, other):
        return (self.b+1)*other.a==self.a*(other.b+1)

    def __lt__(self, other):
        return (self.b+1)*other.a<self.a*(other.b+1)

    def __le__(self, other):
        return (self.b+1)*other.a<=self.a*(other.b+1)

    def __gt__(self, other):
        return (self.b+1)*other.a>self.a*(other.b+1)

    def __ge__(self, other):
        return (self.b+1)*other.a>=self.a*(other.b+1)

from itertools import accumulate
from bisect import bisect
def main():
    inf=10**9+7
    n,t=MI()
    ab=LLI(n)
    ss=[]
    a0=[]
    for a,b in ab:
        if a==0:a0.append(b+1)
        else:ss.append(Store(a,b))
    n=len(ss)
    ss.sort()
    dp=[[inf]*31 for _ in range(n+1)]
    dp[0][0]=0
    for i,s in enumerate(ss):
        a,b=s.a,s.b
        for j in range(30):
            pre=dp[i][j]
            if pre==inf:continue
            nt=a*(pre+1)+b+pre+1
            if nt<=t:dp[i+1][j+1]=min(dp[i+1][j+1],nt)
            dp[i+1][j]=min(dp[i+1][j],pre)
    a0.sort()
    a0=[b for b in accumulate(a0)]
    ans=0
    for j in range(30):
        val=dp[n][j]
        if val==inf:continue
        ans=max(ans,bisect(a0,t-dp[n][j])+j)
    print(ans)

main()