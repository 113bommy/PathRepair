n,m,a,b = map(int,input().split())
x=n%m
print(min((m-x)*a,x*b))
