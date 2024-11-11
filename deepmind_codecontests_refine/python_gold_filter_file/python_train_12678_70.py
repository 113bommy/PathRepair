n,a,b=map(int,input().split())
c=n//(a+b)
j=n%(a+b)
print(c*a+min(j,a))
