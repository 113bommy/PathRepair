n,a,b = map(int, input().split())

x = n//(a+b)
y = min(n%(a+b),a)
print(a*x+y)