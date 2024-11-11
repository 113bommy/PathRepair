def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())
 
import math
 
n=ii()
a=li()
s=sum(a)
b=a.count(100)
if s%400==0:
    print("YES")
else:
    if s%200==0 and b:
        print("YES")
    else:
        print("NO")