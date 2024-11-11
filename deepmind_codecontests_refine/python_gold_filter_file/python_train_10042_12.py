import math
n=int(input())

a=(-1+math.sqrt(1+8*n))/2
b=(-1-math.sqrt(1+8*n))/2
#print(a ,b)
if(a.is_integer()):
    print("YES")
elif(b.is_integer()):
    print("YES")
else:
    print("NO")