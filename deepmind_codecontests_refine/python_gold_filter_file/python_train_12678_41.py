n,a,b=map(int,input().split())
x=n//(a+b)
c=n-(a+b)*x
print(a*x+min(c,a))