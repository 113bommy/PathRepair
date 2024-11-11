from math import cos,pi

t=int(input())
for i in range(t):
    n=int(input())
    theta=pi/n
    maxX=0
    currX=0
    for i in range(n//2+1):
        currX+=cos(theta*(i+1))
        maxX=max(currX,maxX)
    ans=1+2*maxX
    print(ans)