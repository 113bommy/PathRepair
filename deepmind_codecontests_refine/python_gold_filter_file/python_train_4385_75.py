x, y, z, t1, t2, t3=map(int, input().split())
stairs=abs(x-y)*t1
de=abs(x-y)*t2
el=abs(z-x)*t2
elevate=3*t3+el+de
#print(stairs,elevate)
if elevate<=stairs:
    print("YES")
else:
    print("NO")
