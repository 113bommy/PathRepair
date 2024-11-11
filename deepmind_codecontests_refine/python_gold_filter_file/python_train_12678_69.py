n,a,b=map(int,input().split())
l=n//(a+b)
r=n%(a+b)
print(l*a+min(r,a))