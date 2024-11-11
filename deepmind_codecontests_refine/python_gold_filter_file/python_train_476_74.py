s, v1, v2, t1, t2=[int(i) for i in input().split()]
v1=(v1*s)+(2*t1)
v2=(v2*s)+(2*t2)
if v1==v2:
    print("Friendship")
else:
    print("First" if v1<v2 else "Second")