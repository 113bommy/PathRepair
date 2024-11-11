n,a,b=map(int,input().split())
k=n//(a+b)
l=n%(a+b)
print(k*a+min(l,a))