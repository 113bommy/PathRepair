x,y,s=map(int,input().split())
x,y=abs(x),abs(y)
if x+y<=s :
    if x+y==s:print("Yes")
    elif x+y<s and (s-x-y)%2==0:print("Yes")
    else:print("No")
else:print("No")