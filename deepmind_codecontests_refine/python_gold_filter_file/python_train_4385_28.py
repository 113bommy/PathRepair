x,y,z,t1,t2,t3=map(int,input().split())
a=t1*(abs(x-y))
b=t2*(abs(z-x))+3*(t3)+t2*(abs(x-y))
if a>=b:
    print("YES")
else:
    print("NO")
