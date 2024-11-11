#rough code
n,m,a,b=map(int,input().split())
p=n*a
q=(n//m)*b+min((n%m)*a,b)
print(min(p,q))