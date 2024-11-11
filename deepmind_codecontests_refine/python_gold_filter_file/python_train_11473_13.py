def eu(x,y):
    if x%y == 0:
        return y
    elif y%x == 0:
        return x
    elif x > y:
        return eu(x%y, y)
    else:
        return eu(x, y%x)
t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if eu(a, b) == 1:
        print('Finite')
    else:
        print('Infinite')