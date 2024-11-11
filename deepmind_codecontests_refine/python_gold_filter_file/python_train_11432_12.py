from bisect import bisect_right
import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

class mint:
    def __init__(self, x):
        self.__x = x % md

    def __repr__(self):
        return str(self.__x)

    def __neg__(self):
        return mint(-self.__x)

    def __add__(self, other):
        if isinstance(other, mint): other = other.__x
        return mint(self.__x + other)

    def __sub__(self, other):
        if isinstance(other, mint): other = other.__x
        return mint(self.__x - other)

    def __rsub__(self, other):
        return mint(other - self.__x)

    def __mul__(self, other):
        if isinstance(other, mint): other = other.__x
        return mint(self.__x * other)

    __radd__ = __add__
    __rmul__ = __mul__

    def __truediv__(self, other):
        if isinstance(other, mint): other = other.__x
        return mint(self.__x * pow(other, md - 2, md))

    def __rtruediv__(self, other):
        return mint(other * pow(self.__x, md - 2, md))

    def __pow__(self, power, modulo=None):
        return mint(pow(self.__x, power, md))

md = 10**9+7

def main():
    n,x=MI()
    ss=LI()
    ss.sort()
    dp=[0]*(x+1)
    dp[x]=mint(1)
    for i in range(x,0,-1):
        pre=dp[i]
        if pre==0:continue
        mxj=bisect_right(ss,i)
        for j in range(mxj):
            dp[i%ss[j]]+=pre/mxj

    ev=sum(dp[i]*i for i in range(ss[0]))
    fac=mint(1)
    for i in range(1,n+1):fac*=i
    print(ev*fac)

main()