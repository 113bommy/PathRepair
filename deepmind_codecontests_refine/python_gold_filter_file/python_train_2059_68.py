a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())

d=abs(a-b)


if(v*t>=w*t+d): print("YES")
else:print("NO");
