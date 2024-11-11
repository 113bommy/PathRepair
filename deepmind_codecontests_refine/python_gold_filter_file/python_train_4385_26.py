x,y,z,t1,t2,t3 = map(int, input().split())
 
if abs(x-y) * t1 >= 3*t3 + t2*abs(x-z) + t2*abs(x-y):
    print("YES")
else:
    print("NO")

