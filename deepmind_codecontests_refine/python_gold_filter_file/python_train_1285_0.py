import math
k, b, n, t = map(int, input().split(' '))
if k == 1:
    cur = n*b+1
    print(max(math.ceil((-t + n*b + 1)/b), 0))
else:
    god = (b+k-1)/(b+t*k-t)
    m = 0
    while not (k**(m-n) >= god):
        m += 1
    print(m)
