a,b=list(map(int,input().split()))
d={1:-1,0:1}
j=abs(a)+abs(b)
f,k,h,g=d[a+b!=j],d[a<0 and b<0],a>=0,a<0
for i in [g*f,h*f,h*k,g*k]:
    print(i*j,end=' ')