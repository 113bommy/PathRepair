import math
a,b=map(int,input().split())
if a==b:
    print("=")
    exit()
x=math.log(a)*b
y=math.log(b)*a
if(x<y):
    print("<")
elif (x>y):
    print(">")
else:
    print("=")