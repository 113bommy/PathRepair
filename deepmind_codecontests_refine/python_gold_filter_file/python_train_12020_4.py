n,m,a,b=map(int,input().split())
print(min(n*a,(n//m)*b+min((n%m)*a,b)))
