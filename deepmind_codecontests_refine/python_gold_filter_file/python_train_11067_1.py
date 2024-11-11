n,xo=map(int,input().split())
L=[]
c=0
M=0
m=10**18
for i in range(n):
    a,b=map(int,input().split())
    a,b=min(a,b),max(a,b)
    while(a>xo):
        c+=1
        xo=xo+1
    while(b<xo):
        c+=1
        xo=xo-1
    M=max(M,a)
    m=min(m,b)
    
    if(M>xo or m<xo):
        c=-1
        break
    
print(c)