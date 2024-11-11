n,a,b=list(map(int,input().split()))
print(n//(a+b)*a+min(a,n%(a+b)))