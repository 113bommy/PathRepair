a, b = map(int, input().split())
m = max(a+b, a-b, a*b)
print(m)