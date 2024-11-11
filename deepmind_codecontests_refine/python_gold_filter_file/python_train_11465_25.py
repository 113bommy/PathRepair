import math
for T in range(int(input())):
    d = int(input())
    if(d*d < 4*d):
        print("N")
    else:
        b = (d+math.sqrt(d*d - 4*d))/2
        a= d-b
        print("Y",end=" ")
        print("%.20f %.20f"%(a,b))
