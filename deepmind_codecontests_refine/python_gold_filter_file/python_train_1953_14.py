import math
a,b=map(int,input().split())
c=b*math.log(a)
d=a*math.log(b)
if c>d:
    print(">")
if c<d:
    print("<")
if c==d:
    print("=") 