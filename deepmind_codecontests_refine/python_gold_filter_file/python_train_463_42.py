import math
b=list(input().split())
b=[int(i) for i in b]
a=math.sqrt((b[1]-b[3])**2+(b[2]-b[4])**2)
if a%(2*b[0])==0:
    print(int(a//(2*b[0])))
else:
    print(int(a//(2*b[0])+1))