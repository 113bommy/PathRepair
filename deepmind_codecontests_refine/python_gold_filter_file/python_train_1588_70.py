import math
t = int(input())
for g in range(t):
    n = int(input())
    if(n==2):
        print("1.000000000")
        continue
    n=2*n
    ang = 360/n
    a = ((180-ang)/2)*0.0174532925
    c = math.tan(a)
    print("{0:.9f}".format(c))
