s,v1,v2,t1,t2=map(int,input().split())
if 2*t1+v1*s > 2*t2+v2*s:
    print("Second")
elif 2*t1+v1*s < 2*t2+v2*s:
    print("First")
else:
    print("Friendship")