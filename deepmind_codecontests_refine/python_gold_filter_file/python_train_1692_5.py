#Codeforce - - Johnny and Ancient Computer
import math
t = int(input())
while t!=0:
    a,b = map(int,input().split())
    less = 0
    great = 0
    if a<b:
        less = a
        great = b
    else:
        less = b
        great = a
    step = 0
    while less<great:
        less = less<<1
        step += 1
    result = -1
    if less > great:
        result = -1
    else:
        if step%3==0:
            result = int(step/3)
        else:
            result = math.floor(step/3) +1
    print(result)
    t-=1