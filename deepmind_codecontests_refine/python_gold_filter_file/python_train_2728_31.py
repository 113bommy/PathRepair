def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi()) 

import math

for i in range(ii()):
    n=ii()
    a=li()
    f=0
    for i in range(n-1):
        if abs(a[i+1]-a[i])>1:
            f=1
            print("YES")
            print(i+1,i+2)
            break 
    if f==0:
        print("NO")