s,v1,v2,t1,t2 = map(int, input().split())

p1 = s * v1 + t1
p2 = s * v2 + t2
ft1 = p1 + t1
ft2 = p2 + t2
if ft1 < ft2:
    print("First")
elif ft1 > ft2:
    print("Second")
else:
    print("Friendship")