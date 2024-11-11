#######puzzleVerma#######


import sys
import math
mod = 10**9+7


LI=lambda:[int(k) for k in input().split()]
input = lambda: sys.stdin.readline().rstrip()
IN=lambda:int(input())
S=lambda:input()
r=range

# Python program to print prime factors

import math

def prime(n):
    if n<2:
        return False
    if n==2:
        return True
    if (n>2 and n%2==0):
        return False
    ans=True
    for i in range(3,int(n**0.5+1),2):
        if n%i==0:
            ans=False
            break
    return ans



def primeNumbers(n):
    pn=[]
    if n>=2:
        pn.append(2)
    for i in range(3,n+1,2):
        if prime(i):
            pn.append(i)
    return pn

pn=primeNumbers(10**5)    

def primeFactors(n):
    pf=[]
    while (n%2==0):
        pf.append(2)
        n=n//2
    ind=0
    while 1:
        pni=pn[ind]
        if (pni**2)>n:
            break
        while n%pni==0:
            pf.append(pni)
            n//=pni
        ind+=1
    if n>2:
        pf.append(n)

    return pf


for t in r(IN()):
    a,b,k=LI()
    if k==1:
        if a==b:
            print("NO")
        elif (max(a,b)%min(a,b)==0):
            print("YES")
        else:
            print("NO")
    else:
        k1=len(primeFactors(a))
        k2=len(primeFactors(b))
        if k<=(k1+k2):
            print("YES")
        else:
            print("NO")


    
