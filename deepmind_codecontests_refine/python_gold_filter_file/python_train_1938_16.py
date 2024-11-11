import math 
def chop():
    return (int(i) for i in input().split())
f=False
r,d=chop()
n=int(input())
r2=r-d
l=0
for i in range(n):
    x,y,t=chop()
    if (x**2+y**2<=r**2) and (x**2+y**2>=r2**2):
        d=math.sqrt(x**2+y**2)
        if (r>=d+t) and (r2<=d-t):
            l+=1
print(l)
    