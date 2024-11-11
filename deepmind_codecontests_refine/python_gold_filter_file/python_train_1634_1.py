n,m,a,b = map(int,input().split())
q = n % m
print(min(q*b,(m-q)*a))
