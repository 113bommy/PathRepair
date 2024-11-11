n,m,a,b=map(int,input().split())

k = n%m
print(min(a*(m-k),b*k))