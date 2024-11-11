n,a,b=map(int,input().split())
l,r=n//(a+b),n%(a+b)
print(l*a+min(r,a))