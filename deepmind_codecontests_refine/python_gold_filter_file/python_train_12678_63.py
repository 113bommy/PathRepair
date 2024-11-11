n,a,b=map(int,input().split())
k=n//(a+b)
print(k*a+min(a,n-k*(a+b)))
