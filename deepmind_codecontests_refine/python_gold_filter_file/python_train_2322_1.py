def f(a, b):
    k = 0
    while a > 0:
        a = a//b
        k += 1
    return k
T, = map(int, input().split())
for _ in range(T):
    a, b = map(int, input().split())
    g = 0
    if a == 1 and b == 1:
        print(2)
        continue
    if b == 1:
        b += 1
        g = 1
    R = 10**18
    for j in range(min(1000, a+2)):
        r = g + j + f(a, b)
        b += 1
        R=min(R, r)
    print(R)
