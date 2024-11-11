#############<------------  Xorcestor_X ---------------->############

from math import *


def is_even(p):
    n=len(p)
    count=0
    for i in range(n):
        index=p.index(i,i,n)
        if i==index:
            pass
        else:
            count+=1
            temp=p[i]
            p[i]=p[index]
            p[index]=temp
    # print(p)
    if count%2==0:
        return True
    else:
        return False



prime=[]

def SieveOfEratosthenes():
    global prime
    prime=[1]*2000010
    prime[1]=0
    p=2
    while p*p<=2000001:
        if prime[p]:
            for i in range(p*p,2000002,p):
                prime[i]=0

lpf=[]

def precompute():
    global lpf
    lpf=[0]*1000001
    for i in range(2,1000001):
        if not lpf[i]:
            for j in range(i,1000001,i):
                if not lpf[j]:
                    lpf[j]=i


def binpow(a,b):
    res=1
    while b>0:
        if b&1:
            res*=a
        a*=a
        b>>=1
    return res


def modpow(a,b,x):
    res=1
    while b>0:
        if b&1:
            res*=a
            res%=x
        a*=a
        a%=x
        b>>=1
    return res

cont=[]

def f(x):
    global cont
    total=0
    for i in cont:
        total+=abs(i-x)
    return total


def bs(low,high,target):
    while low+3<high:
        mid=(low+high)/2
        if arr[mid]<target:
            low=mid
        else:
            high=mid-1
    for i in range(high,low-1,-1):
        if arr[o]<target:
            return i
    return -1


def ternary_search(l,r):
    while r-l>10:
        m1=l+(r-l)/3
        m2=r-(r-l)/3
        f1=f(m1)
        f2=f(m2)
        if f1>f2:
            l=m1
        else:
            r=m2

    mino=f(l)

    for i in range(l,r+1):
        mino=min(mino,f(i))

    return mino

s=input()
l=s.split('.')
n=len(l)
if n==0 or n==1:
    print('NO')
    quit()
glob=[]
b=True
if len(l[0])>8 or len(l[0])==0:
    b=False
if len(l[-1])>3 or len(l[-1])==0:
    b=False

if n==1:
    if b:
        print("YES")
        print(s)
        quit()
    else:
        print("NO")
        quit()

glob.append(l[0]+'.')

for i in range(1,n-1):
    if 2<=len(l[i])<=11:
        if len(l[i])<=9:
            glob[i-1]+=l[i][0:1]
            glob.append(l[i][1:]+'.')
        else:
            glob[i-1]+=l[i][0:-8]
            glob.append(l[i][-8:]+'.')
    else:
        b=False
        break

glob[-1]+=l[-1]
if b:
    print('YES')
    for a in glob:
        print(a)
else:
    print('NO')
