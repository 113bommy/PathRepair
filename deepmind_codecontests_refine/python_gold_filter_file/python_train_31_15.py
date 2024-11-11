
import math 

try:
    t=1
    while(t):
        t-=1
        #s=input()
        n,x,y=map(int,input().split())
        #print()
        print(max(math.ceil((y*n)/100)-x,0))
        

except:
    pass
