import sys
sys.setrecursionlimit(10**7) #再帰関数の上限,10**5以上の場合python
import math
from copy import copy, deepcopy
from copy import deepcopy as dcp
from operator import itemgetter
from bisect import bisect_left, bisect, bisect_right#2分探索
#bisect_left(l,x), bisect(l,x)#aはソート済みである必要あり。aの中からx未満の要素数を返す。rightだと以下
from collections import deque, defaultdict
#deque(l), pop(), append(x), popleft(), appendleft(x)
#q.rotate(n)で → にn回ローテート
from collections import Counter#文字列を個数カウント辞書に、
#S=Counter(l),S.most_common(x),S.keys(),S.values(),S.items()
from itertools import accumulate,combinations,permutations,product#累積和
#list(accumulate(l))
from heapq import heapify,heappop,heappush
#heapify(q),heappush(q,a),heappop(q) #q=heapify(q)としないこと、返り値はNone
from functools import reduce,lru_cache#pypyでもうごく
#@lru_cache(maxsize = None)#maxsizeは保存するデータ数の最大値、2**nが最も高効率
from decimal import Decimal

def input(): 
    x=sys.stdin.readline()
    return x[:-1] if x[-1]=="\n" else x
def printe(*x):print("## ",*x,file=sys.stderr)
def printl(li): _=print(*li, sep="\n") if li else None
def argsort(s, return_sorted=False): 
    inds=sorted(range(len(s)), key=lambda k: s[k])
    if return_sorted: return inds, [s[i] for i in inds]
    return inds
def alp2num(c,cap=False): return ord(c)-97 if not cap else ord(c)-65
def num2alp(i,cap=False): return chr(i+97) if not cap else chr(i+65)
def matmat(A,B):
    K,N,M=len(B),len(A),len(B[0])
    return [[sum([(A[i][k]*B[k][j]) for k in range(K)]) for j in range(M)] for i in range(N)]
def matvec(M,v):
    N,size=len(v),len(M)
    return [sum([M[i][j]*v[j] for j in range(N)]) for i in range(size)]
def T(M):
    n,m=len(M),len(M[0])
    return [[M[j][i] for j in range(n)] for i in range(m)]
def binr(x): return bin(x)[2:]
def bitcount(x): #xは64bit整数
    x= x - ((x >> 1) & 0x5555555555555555)
    x= (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x= (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f 
    x+= (x >> 8); x+= (x >> 16); x+= (x >> 32) 
    return x & 0x7f

def main():
    
    #w.sort(key=itemgetter(1),reverse=True)  #二個目の要素で降順並び替え

    p = int(input())
    #N, K = map(int, input().split())
    A = tuple(map(int, input().split())) #1行ベクトル
    #L = tuple(int(input()) for i in range(N)) #改行ベクトル
    #S = tuple(tuple(map(int, input().split())) for i in range(N)) #改行行列
    mod = p
    maxn=p
    fact=[1]*(maxn+1)#NはnCrの最大のn
    invs=[1]*(maxn+1);invs[0]=0
    ifact=[1]*(maxn+1)
    for i in range(2,maxn+1):
        fact[i]=(fact[i-1]*i)%mod
        invs[i]=invs[mod%i]*(-(mod//i))%mod
        ifact[i]=(ifact[i-1]*invs[i])%mod
    def perm(n,r): return fact[n]*ifact[n-r]%mod
    def comb(n,r): return (fact[n]*ifact[r]%mod)*ifact[n-r]%mod
    def multicomb(self,n,*rs):#n!/(r1!*r2!*r3!*...)
        ans=fact[n]
        for r in rs: ans=(ans*self.ifact[r])%self.mod
        return ans
    
    tot=[0]*p
    tot[0]=sum(A)%mod
    for i in range(p):
        a=A[i]
        if not a:
            continue
        #sgn=pow(-1,p-1)
        mi=(-i)%mod
        base=pow(mi,p-1,mod)
        
        for j in range(p):
            if j==p-1:
                base=1
            tot[j]-=base*comb(p-1,j)%mod
            tot[j]%=mod
            base*=invs[mi]
            base%=mod

    
    print(*tot)


if __name__ == "__main__":
    main()