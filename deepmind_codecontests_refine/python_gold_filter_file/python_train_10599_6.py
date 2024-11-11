import sys,bisect,string,math,time,functools,random,fractions
from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
from itertools import permutations,combinations,groupby
rep=range;R=range
def Golf():n,*t=map(int,open(0).read().split())
def I():return int(input())
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def MI():return map(int,input().split())
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def StoLI():return [ord(i)-97 for i in input()]
def ItoS(n):return chr(n+97)
def LtoS(ls):return ''.join([chr(i+97) for i in ls])
def RA():return map(int,open(0).read().split())
def GI(V,E,ls=None,Directed=False,index=1):
    org_inp=[];g=[[] for i in range(V)]
    FromStdin=True if ls==None else False
    for i in range(E):
        if FromStdin:
            inp=LI()
            org_inp.append(inp)
        else:
            inp=ls[i]
        if len(inp)==2:
            a,b=inp;c=1
        else:
            a,b,c=inp
        if index==1:a-=1;b-=1
        aa=(a,c);bb=(b,c);g[a].append(bb)
        if not Directed:g[b].append(aa)
    return g,org_inp
def GGI(h,w,search=None,replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1):
    #h,w,g,sg=GGI(h,w,search=['S','G'],replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1) # sample usage
    mp=[boundary]*(w+2);found={}
    for i in R(h):
        s=input()
        for char in search:
            if char in s:
                found[char]=((i+1)*(w+2)+s.index(char)+1)
                mp_def[char]=mp_def[replacement_of_found]
        mp+=[boundary]+[mp_def[j] for j in s]+[boundary]
    mp+=[boundary]*(w+2)
    return h+2,w+2,mp,found
def TI(n):return GI(n,n-1)
def accum(ls):
    rt=[0]
    for i in ls:rt+=[rt[-1]+i]
    return rt
def bit_combination(n,base=2):
    rt=[]
    for tb in R(base**n):s=[tb//(base**bt)%base for bt in R(n)];rt+=[s]
    return rt
def gcd(x,y):
    if y==0:return x
    if x%y==0:return y
    while x%y!=0:x,y=y,x%y
    return y
def YN(x):print(['NO','YES'][x])
def Yn(x):print(['No','Yes'][x])
def show(*inp,end='\n'):
    if show_flg:print(*inp,end=end)

mo=10**9+7
inf=float('inf')
FourNb=[(-1,0),(1,0),(0,1),(0,-1)];EightNb=[(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)];compas=dict(zip('WENS',FourNb));cursol=dict(zip('LRUD',FourNb))
l_alp=string.ascii_lowercase
#sys.setrecursionlimit(10**7)
read=sys.stdin.buffer.read;readline=sys.stdin.buffer.readline;input=lambda:sys.stdin.readline().rstrip()

########################################################################################################################################################################
# Verified by 
# https://atcoder.jp/contests/abc014/tasks/abc014_4
# https://atcoder.jp/contests/abc133/tasks/abc133_f

# import SparseTable
# initialize
# Tree() => n; (a,b);*(n-1)
# Tree(n) => (a,b);*(n-1)
# Tree(init=False); Tree.stdin(); => n; (a,b);*(n-1)
# Tree(init=False); Tree.listin(ls,index=0); => (a,b);*(n-1)

import sys,bisect,string,math,time,functools,random,fractions
from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
from itertools import permutations,combinations,groupby
rep=range
def Golf():n,*t=map(int,open(0).read().split())
def I():return int(input())
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def MI():return map(int,input().split())
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def StoLI():return [ord(i)-97 for i in input()]
def ItoS(n):return chr(n+97)
def LtoS(ls):return ''.join([chr(i+97) for i in ls])
def RA():return map(int,open(0).read().split())
def GI(V,E,ls=None,Directed=False,index=1):
    org_inp=[];g=[[] for i in range(V)]
    FromStdin=True if ls==None else False
    for i in range(E):
        if FromStdin:
            inp=LI()
            org_inp.append(inp)
        else:
            inp=ls[i]
        if len(inp)==2:
            a,b=inp;c=1
        else:
            a,b,c=inp
        if index==1:a-=1;b-=1
        aa=(a,c);bb=(b,c);g[a].append(bb)
        if not Directed:g[b].append(aa)
    return g,org_inp
def GGI(h,w,search=None,replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1):
    #h,w,g,sg=GGI(h,w,search=['S','G'],replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1) # sample usage
    mp=[boundary]*(w+2);found={}
    for i in range(h):
        s=input()
        for char in search:
            if char in s:
                found[char]=((i+1)*(w+2)+s.index(char)+1)
                mp_def[char]=mp_def[replacement_of_found]
        mp+=[boundary]+[mp_def[j] for j in s]+[boundary]
    mp+=[boundary]*(w+2)
    return h+2,w+2,mp,found
def TI(n):return GI(n,n-1)
def accum(ls):
    rt=[0]
    for i in ls:rt+=[rt[-1]+i]
    return rt
def bit_combination(n,base=2):
    rt=[]
    for tb in range(base**n):s=[tb//(base**bt)%base for bt in range(n)];rt+=[s]
    return rt
def gcd(x,y):
    if y==0:return x
    if x%y==0:return y
    while x%y!=0:x,y=y,x%y
    return y
def YN(x):print(['NO','YES'][x])
def Yn(x):print(['No','Yes'][x])
def show(*inp,end='\n'):
    if show_flg:print(*inp,end=end)

mo=10**9+7
inf=float('inf')
FourNb=[(-1,0),(1,0),(0,1),(0,-1)];EightNb=[(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)];compas=dict(zip('WENS',FourNb));cursol=dict(zip('LRUD',FourNb))
l_alp=string.ascii_lowercase
#sys.setrecursionlimit(10**7)
read=sys.stdin.buffer.read
readline=sys.stdin.buffer.readline
input=lambda: sys.stdin.readline().rstrip()

## Verified by Yukicoder 1073
## https://yukicoder.me/problems/no/1073
##
## Matrix Class supporting operators +, -, *, %, +=, -=, *=, %=
## *, *= allows int/float/complex
## ** or pow(self,p,mod) for the size N*N matrix is implemented by Repeated squaring. O(N^3*log(p))
##
## Constructor: matrix(array), where array is 1D or 2D array. 1-dimensional array X is modified as 2D array of [X].
##
## methods
## T(): returns transposed matrix
## resize((n,m),fill=0): changes the matrix instance into the new shape (n * m), missing entries are filled with "fill" (default value is zero).


class matrix:
    class MulShapeError(Exception):
        "mult is not applicable between the two matrices given"
        pass

    def __init__(self,arr_input):
        if hasattr(arr_input[0],"__getitem__"):
            self.arr=arr_input
        else:
            self.arr=[arr_input]
        self.shape=(len(self.arr),len(self.arr[0]))

    def __getitem__(self,key):
        return self.arr[key]

    def __setitem__(self,key,value):
        self.arr[key]=value

    def __iter__(self):
        return iter(self.arr)
        
    def __add__(self,B):
        if type(B)!=matrix:
            return NotImplemented
        if B.shape!=self.shape:
            return NotImplemented
        rt=[[0]*self.shape[1] for i in range(self.shape[0])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                rt[i][j]=self.arr[i][j]+B.arr[i][j]
        return matrix(rt)

    def __iadd__(self,B):
        return self.__add__(B)

    def __sub__(self,B):
        if type(B)!=matrix:
            return NotImplemented
        if B.shape!=self.shape:
            return NotImplemented
        rt=[[0]*self.shape[1] for i in range(self.shape[0])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                rt[i][j]=self.arr[i][j]-B.arr[i][j]
        return matrix(rt)

    def __isub__(self,B):
        return self.__sub__(B)

    def __mul__(self,M):
        if type(M) in [int,float,complex]:
            M=matrix([[M*(i==j) for j in range(self.shape[1])] for i in range(self.shape[1])])
        if type(M)!=matrix:
            return NotImplemented
        if M.shape[0]!=self.shape[1]:
            raise matrix.MulShapeError("mult is not applicable between the matrices of shape "+str(self.shape)+" and "+str(M.shape))
        ra,ca=self.shape
        rb,cb=M.shape
        c=[[0]*cb for i in range(ra)]
        for i in range(ra):
            for j in range(cb):
                for k in range(ca):
                    c[i][j]+=self.arr[i][k]*M.arr[k][j]
        return matrix(c)

    def __imul__(self,M):
        return self.__mul__(M)

    def __rmul__(self,M):
        if type(M) in [int,float,complex]:
            M=matrix([[M*(i==j) for j in range(self.shape[1])] for i in range(self.shape[1])])
        if type(M)!=matrix:
            return NotImplemented
        if M.shape[0]!=self.shape[1]:
            raise matrix.MulShapeError("mult is not applicable between the matrix shape "+str(self.shape)+" and "+str(M.shape))
        ra,ca=M.shape
        rb,cb=self.shape
        c=[[0]*cb for i in range(ra)]
        for i in range(ra):
            for j in range(cb):
                for k in range(ca):
                    c[i][j]+=M.arr[i][k]*self.arr[k][j]
        return matrix(c)

    def __mod__(self,p):
        if type(p)!=int:
            return NotImplemented
        c=[[0]*self.shape[1] for i in range(self.shape[0])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                c[i][j]=self.arr[i][j]%p
        return matrix(c)

    def __imod__(self,p):
        return self.__mod__(p)

    def __pow__(self,p,mod=10**9+7):
        if type(p)!=int or self.shape[0]!=self.shape[1]:
            return NotImplemented
        A=matrix(self.arr)
        R=matrix([[1*(i==j) for j in range(self.shape[0])] for i in range(self.shape[0])])
        while p>0:
            if p&1:
                R*=A
                R%=mod
            A*=A
            A%=mod
            p>>=1
        return R

    def __neg__(self):
        return self.__mul__(-1)

    def __str__(self):
        rt='['
        for i in self.arr:
            rt=rt+str(i)+",\n"
        return rt[:-2]+']'

    def T(self):
        rt=[[0]*self.shape[0] for i in range(self.shape[1])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                rt[j][i]=self.arr[i][j]
        return matrix(rt)

    def resize(self,new_shape,fill=0):
        t_arr=[]
        for i in self.arr:
            t_arr+=i
        t_arr.reverse()
        n,m=new_shape
        self.shape=(n,m)
        self.arr=[[fill]*m for i in range(n)]

        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                if t_arr:
                    self.arr[i][j]=t_arr.pop()
        return

    def view(self):
        for i in self.arr:
            print(i)


show_flg=False
show_flg=True

ans=0

n,k=LI()
a=[]
for i in range(n):
    a+=LI(),
M=matrix(a)
M**=k

print(sum([sum(i)for i in M])%mo)

