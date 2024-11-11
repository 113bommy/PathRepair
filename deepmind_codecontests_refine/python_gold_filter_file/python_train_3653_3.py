from math import ceil
a,b,x=map(int,input().split())
s=""
if x&1:
    if a>b:
        s="01"*(x>>1)+"0"*(a-(x>>1))+"1"*(b-(x>>1))
    else:
        s="10"*(x>>1)+"1"*(b-(x>>1))+"0"*(a-(x>>1))
else:
    if a>b:
        s="01"*(x>>1)+"1"*(b-(x>>1))+"0"*(a-(x>>1))
    else:
        s="10"*(x>>1)+"0"*(a-(x>>1))+"1"*(b-(x>>1))    
print(s)        
    
    
    
