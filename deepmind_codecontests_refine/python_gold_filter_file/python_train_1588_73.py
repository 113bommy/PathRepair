import math
t=int(input())
while(t):
    t-=1
    n = int(input())
    n*=2
    a = 1
    print(round(a * math.tan((((n - 2) * 180) / (2 * n)) * 3.14159265358 / 180),6))
     