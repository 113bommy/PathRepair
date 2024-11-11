def gcd(a, b):
    while b > 0:
        temp = a % b
        a = b
        b = temp
    return a
a,b,x,y = map(int,input().split())
gc = gcd(x,y)
x2 = x // gc
y2 = y // gc
x4 = a // x2
y4 = b // y2

if x4 * y2 <= b:
    print(x4)
elif y4 * x2 <= a:
    print(y4)
else:
    print(0)

