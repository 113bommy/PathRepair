x,y,z,t1,t2,t3 = map(int, input().split())
d = abs(x-y)
tel = (abs(z-x) + d)*t2 + 3*t3
ts = d*t1
if tel <= ts:
    print("YES")
else:
    print("NO")