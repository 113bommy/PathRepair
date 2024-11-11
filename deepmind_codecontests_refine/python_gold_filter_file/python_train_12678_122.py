n,a,b=map(int,input().split())
c=n//(a+b)
d=n%(a+b)
print(c*a+min(a,d))