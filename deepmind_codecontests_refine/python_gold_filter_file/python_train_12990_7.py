a, b, n = map(int,input().split())
x = min(n,b-1)
print(int(a*(x%b) / b))