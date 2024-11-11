a, b, c = map(int, input().split())
x = min(a, b)
y = max(a, b)
print(2*(c+x) + (y > x))  