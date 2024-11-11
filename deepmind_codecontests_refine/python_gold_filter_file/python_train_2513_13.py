from math import ceil,sqrt,gcd,log,floor
from collections import deque
def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().strip().split(" "))
def li(): return list(mi())
def msi(): return map(str,input().strip().split(" "))
def lsi(): return list(msi())
#for _ in range(ii()):

n=ii()
s=si()
c=0
for i in range(n-1,-1,-1):
    if(int(s[i])%2==0):
        c+=(i+1)
print(c)