import math
a,b = [int(x) for x in input().split()]
if b-a >= 10 : print(0)
else :
    x = 1
    for i in range(a+1,b+1) : x *= i
    print(str(x)[-1])