a, b, c, x, y = map(int, input().split())
print(min(a*x+b*y, 2*c*x + b*max(0,y-x), 2*c*y + a*max(0, x-y)))