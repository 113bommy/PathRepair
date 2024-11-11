x, y = map(int, input().split())
if (x == 1 and y == 0):
    print(0)
    exit()
a = (4*(x-1)+1 if x > 0 else -4*x-1 if x < 0 else 0)
b = (4*y-2 if y > 0 else -4*y if y < 0 else 0)
if(abs(x) == abs(y) and y>=x or y < 0 and abs(x) > abs(y)):
    print(min(a, b))
else:
    print(max(a, b))
