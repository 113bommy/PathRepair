n, m, a, b = map(int,input().split())
print(min((m*(n//m+1)-n)*a,(n - (m*(n//m)))*b))