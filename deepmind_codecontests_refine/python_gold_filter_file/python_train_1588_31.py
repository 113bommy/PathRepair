import math

t=int(input())
for _ in range(t):
    n=int(input())
    n2=2*n
    h=1/math.tan(math.pi/n2)
    print(h)
