def f(a,b,c,l):
    if a<b+c:
        return 0
    else:
        c=min(l,a-b-c)
        return (c+1)*(c+2)/2

a,b,c,l = map(int,input().split())
z=(l+1)*(l+2)*(l+3)/6
i=0
while i<=l:
    z-=f(a+i,b,c,l-i)+f(b+i,c,a,l-i)+f(c+i,a,b,l-i)
    i+=1
print(int(z))

    
    
