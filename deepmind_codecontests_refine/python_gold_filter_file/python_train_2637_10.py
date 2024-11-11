import sys
import math
from collections import Counter
from collections import OrderedDict
from collections import defaultdict
from functools import reduce
sys.setrecursionlimit(10**6)
def inputt():
    return sys.stdin.readline().strip()
def printt(n):
    sys.stdout.write(str(n)+'\n')
def listt():
    return [int(i) for i in inputt().split()]
 
def gcd(a,b): 
   return math.gcd(a,b) 
 
def lcm(a,b): 
    return (a*b) // gcd(a,b) 

def factors(n):
    step = 2 if n%2 else 1
    return set(reduce(list.__add__,([i, n//i] for i in range(1, int(math.sqrt(n))+1, step) if n % i == 0)))

def comb(n,k):
    factn=math.factorial(n)
    factk=math.factorial(k)
    fact=math.factorial(n-k)
    ans=factn//(factk*fact)
    return ans

def is_prime(n): 
    if n <= 1: 
        return False
    if n == 2: 
        return True
    if n > 2 and n % 2 == 0: 
        return False

    max_div = math.floor(math.sqrt(n)) 
    for i in range(3, 1 + max_div, 2): 
        if n % i == 0: 
            return False
    return True
#t=int(inputt())
t=1
for _ in range(t):
    n=int(inputt())
    li=listt()
    d=Counter(li)
    for i in range(1,5):
        if i not in d:
            d[i]=0
    ans=0
    ans+=d[4]
    ans+=d[3]
    d[1]-=d[3]
    if d[1]<0:
        d[1]=0
    if d[2]%2==0:
        ans+=d[2]//2
        d[2]=0
        ans+=math.ceil(d[1]/4)
    else:
        ans+=math.ceil(d[2]/2) 
        if d[1]>0:  
            d[1]-=2
        if d[1]>0:
            ans+=math.ceil(d[1]/4)
    printt(ans)        
    