n,a,b=map(int,input().split())
k=n//(a+b)
l=n-k*(a+b)
print(k*a+min(a,l))