ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
lx=lambda x:map(int,input().split(x))
#from math import log10 ,log2,ceil,factorial as fac,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
#from bisect import bisect_right as br,bisect_left as bl
#from collections import Counter
 
 
 
#for _ in range(t()):
def f():
    n=t()
    
    s=ss()

    a=0
    b=0
    c=0
    if n%2==1:
        print(-1)
        return 
    for i in s:
        if i=="(":
            
            a+=1
        elif i==")":
            a-=1
            if a<0:
                c+=2
            
            
    
    print(c if a==0 else -1)
    
f()
