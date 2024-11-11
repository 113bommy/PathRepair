s,v1,v2,t1,t2=list(map(int,input().split()))
f1=2*t1+(s*v1)
f2=2*t2+(s*v2)
if f1==f2:
    print("Friendship")
elif f1<f2:
    print("First")
elif f2<f1:
    print("Second")