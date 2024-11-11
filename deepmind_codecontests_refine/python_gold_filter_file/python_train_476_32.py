l,v1,v2,t1,t2 = list(map(int,input().split()))
v1 = v1*l + 2*t1
v2 = v2*l + 2*t2

if v1>v2:
    print("Second")
elif v1<v2:
    print("First")
else:
    print("Friendship")