x,y,z,t1,t2,t3=map(int,input().split())
a1=abs(x-y)*t1
a2=abs(x-z)*t2+3*t3+abs(x-y)*t2
if a1>=a2:
    print("YES")
else:
    print("NO")
