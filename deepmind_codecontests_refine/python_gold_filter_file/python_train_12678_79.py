n,a,b=map(int,input().split())
x=n//(a+b)
y=n%(a+b)
print(x*a+min(a,y))