x,y,z,t1,t2,t3=map(int,input().split())
a=t2*(abs(x-z)+abs(x-y))+3*t3
b=t1*(abs(x-y))
if a>b:
    print("NO")
else:
    print("YES")