import collections
import sys
import io, os
import math
from heapq import *
gcd = math.gcd
sqrt = math.sqrt
def ceil(a,b):
    a=-a
    k=a//b
    k=-k
    return k
# arr=list(map(int, input().split()))
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def strinp(testcases):
    k = 5
    if (testcases == -1 or testcases == 1):
        k = 1
    f = str(input())
    f = f[2:len(f) - k]
    return f
def lcm(l):
    ans=l[0]
    for i in range(1,len(l)):
        ans=((ans*l[i])//gcd(ans,l[i]))
    return ans
def main():
    t=1
    for _ in range(t):
        k=int(input())
        mod=(10**9)+7
        tot=pow(2,k)-1
        ans=6*pow(4,tot-1,mod)
        ans%=mod
        print(ans)
main()