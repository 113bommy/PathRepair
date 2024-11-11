a,v1,v2,t1,t2=map(int,input().split())
f=a*v1+2*t1
s=a*v2+2*t2
if f<s:
    print("First")
elif s<f:
    print("Second")
else:
    print("Friendship")