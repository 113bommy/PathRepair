x,k,d=map(int,input().split())
x=abs(x)
a,b=x//d,x%d
if k<=a:
    print(x-k*d)
else:
    print(abs(b-d*((k-a)%2==1)))