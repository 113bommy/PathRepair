n,m,a,b=map(int,input().split())
k=n%m
print(min(k*b,(m-k)*a))