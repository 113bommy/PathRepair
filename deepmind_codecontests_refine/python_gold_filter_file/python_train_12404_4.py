n,m,r=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split() ))
x=min(a)
y=max(b)
if(x>=y):
    print(r)
else:
    print((r//x)*y+(r%x))

