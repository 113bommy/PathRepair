n,a,b=map(int,input().split())
A=n//(a+b)
B=n%(a+b)
print(a*A+min(a,B))