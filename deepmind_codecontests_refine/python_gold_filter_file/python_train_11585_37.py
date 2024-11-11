t = int(input())
import math
for i in range(0,t):
    a,b = map(int,input().split())
    if(a!=b):
        print(math.ceil(abs(b-a)/10))
    else:
        print(0)