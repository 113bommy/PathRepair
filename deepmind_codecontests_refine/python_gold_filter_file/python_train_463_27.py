import math
a=list(map(int,input().strip().split(' ')))
r=a[0]
x1=a[1]
y1=a[2]
x2=a[3]
y2=a[4]
d = (x2-x1)**2+(y1-y2)**2
s=d*1.00
s=math.sqrt(s)
s=s/(2*r)
c=int(s)
if(c==s):
    print(c)
else:
    c=c+1
    print(c)