import math
t=int(input())
for i in range(t):
    a,b,c,d,k=[int(x) for x in input().split()]
    pn=math.ceil(a/c)
    pncl=math.ceil(b/d)
    if pn+pncl<=k:
        print(str(pn)+" "+str(k-pn))
    else:
        print('-1')
        
    
    