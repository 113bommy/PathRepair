from math import *

#from math import factorial as fact, comb as ncr 
from bisect import bisect_left as bl
from bisect import bisect_right as br
from collections import Counter as ctr
from collections import deque as dq

from array import array
from re import search

li=lambda : list(map(int,input().split()))
arr=lambda a: array('i',a)
bi=lambda n: bin(n).replace("0b", "")
yn=lambda f: print('NYOE S'[f::2])
sbstr=lambda a,s: search('.*'.join(a),s)
'''
def isprime(a):
    if a==2: return True
    elif a%2==0: return False
    n=3
    while n<=a**0.5:
        if a%n==0:
            return False
        n+=2
    return True

def nf(n,a):
    b=a*a
    c=b*a
    d=c*a
    e=n
    ct=0
    while e%a==0:
        if e%d==0:
            ct+=4
            e=e//d
        if e%c==0:
            ct+=3
            e=e//c
        if e%b==0:
            ct+=2
            e=e//b
        if e%a==0:
            ct+=1
            e=e//a
    return ct
'''

def smnd(n):
    for i in range(2,n+1):
        if n%i!=0:
            return i
        return n+1

def solve():
    for _ in range(int(input())):
        n=int(input())
        a=li()
        if n%2==0:
            print("YES")
        else:
            for i in range(n-1):
                if a[i]>=a[i+1]:
                    print("YES")
                    break
            else:
                print("NO")
solve()