n,a,b=map(int,input().split())
print(a*(n//(a+b))+min(a,n%(a+b)))