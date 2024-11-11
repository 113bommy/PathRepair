f=lambda: map(int,input().split())

def nod(a,b):
    while True:
        if a%b==0:
            return b
        if b%a==0:
            return a
        if a>b:
            a,b=b,a%b
        else:
            a,b=b%a,a

l,r,x,y=f()

if y%x!=0:
    print(0)
else:
    k=0
    z = int(y / x)
    for c in range(1,int(z**0.5)+1):
        if z % c==0:
            d = int(z / c)
            if l<=c*x and c*x<=r and l<=d*x and d*x<=r and nod(c,d)==1:
                k+=1
                if c*c!=z: k+=1
    print(k)
            
