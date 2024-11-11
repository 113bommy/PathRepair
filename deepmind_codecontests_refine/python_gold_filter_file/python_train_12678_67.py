n,a,b=map(int,input().split())
x=n%(a+b)
y=n//(a+b)
print(y*a+min(x,a))