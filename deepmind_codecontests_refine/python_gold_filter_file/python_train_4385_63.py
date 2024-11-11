# #code
# print("GfG")
x,y,z,t1,t2,t3 = map(int,input().split())
d1 = t1 * abs(x-y)
d2 = (abs(z-x))*t2 + 2*t3 + abs(x-y)*t2 + t3
if d2 <= d1:
    print("YES")
else:
    print("NO")
