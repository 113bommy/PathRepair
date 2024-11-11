import math
n=int(input())
s=list(map(int,input().split()))
b=[0,0,0,0]
for i in range(n):
    b[s[i]-1]=b[s[i]-1]+1
r=0
r=b[3]+b[2]+math.ceil(b[1]/2)
space=b[2]+(math.ceil(b[1]/2)*2-b[1])*2
if space>b[0]:
    print(r)
else:
    b[0]=b[0]-space
    r=r+math.ceil(b[0]/4)
    print(r)