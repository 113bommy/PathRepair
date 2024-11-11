a, b, c=map(int, input().split())

x=a+b+c
y=2*a+2*b
# print(y)
print(min(x, y, 2*(a+c), 2*(b+c)))