s,v1,v2,t1,t2=map(int,input().split())
z1=2*t1+s*v1
z2=2*t2+s*v2
if z1<z2:
    print("First")
elif z2<z1:
    print("Second")
elif z1==z2:
    print("Friendship")
