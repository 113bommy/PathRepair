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
a=li()
s=0
for i in range(n):
    s1=a[i]
    s2=a[i]
    for j in range(i+1,n):
        s1^=a[j]
        s2=max(s2,s1)
    s=max(s,s2)
print(s)
        
        