n,a,b=map(int,input().split())
c=n//(a+b)
d=n%(a+b)
print(a*c+min(d, a))