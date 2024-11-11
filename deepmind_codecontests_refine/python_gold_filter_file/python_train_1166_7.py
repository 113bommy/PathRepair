a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
if(e<f):
    k=min(b,c,d)
    d=d-k
    k=k*f
    n=min(d,a)
    m=e*n
    print(k+m)
else:
    n=min(d,a)
    d=d-n
    m=e*n
    k=min(b,c,d)
    
    k=k*f
   
    print(k+m)
    
