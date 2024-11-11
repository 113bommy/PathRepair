import math
x=float(input())
if x%2 == 0 :
    if x/4 == math.floor(x/4):
        c= (x/4)-1
    else :
        c= math.floor(x/4)
else :
    c=0
print (int(c))
