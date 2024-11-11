import math
temp = map(int, input().split(' '))
n, x, y = temp
q = sorted(list(map(int,input().split(' '))))
t = 0
if x>y:
    print(n)
else:
    for i in range(0, n):
        if q[i]<=x:
            t = t + 1
    print(math.ceil(t/2))