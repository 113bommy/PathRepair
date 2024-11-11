n=int(input())
import sys
pts=[]
for i in range(n):
    x,y=map(int,input().split())
    pts.append([x,y])
if(n<=4):
    print('YES')
    sys.exit()
b1=pts[0][0]-pts[1][0]
a1=pts[1][1]-pts[0][1]
c1=-a1*pts[0][0] - b1*pts[0][1]
a2=0
b2=0
c2=1
p=[]
flag=True
for i in range(n):
    if(a1*pts[i][0]+b1*pts[i][1]+c1!=0 and a2*pts[i][0]+b2*pts[i][1]+c2!=0 ):
        p.append(pts[i])
        if(len(p)==2):
            
            b2=p[0][0]-p[1][0]
            a2=p[1][1]-p[0][1]
            c2=-a2*p[0][0] - b2*p[0][1]
        if(len(p)>2):
            flag=False
            break
if(flag):
    print("YES")
    #print(1,p)
    sys.exit()
P=p
p=[pts[0],P[0]]
b1=p[0][0]-p[1][0]
a1=p[1][1]-p[0][1]
c1=-a1*p[0][0] - b1*p[0][1]
p=[]
a2=0
b2=0
c2=1
flag=True
for i in range(n):
    if(a1*pts[i][0]+b1*pts[i][1]+c1!=0 and a2*pts[i][0]+b2*pts[i][1]+c2!=0 ):
        p.append(pts[i])
        #print('here in 2 ',pts[i])
        if(len(p)==2):
            
            b2=p[0][0]-p[1][0]
            a2=p[1][1]-p[0][1]
            c2=-a2*p[0][0] - b2*p[0][1]
        if(len(p)>2):
            flag=False
            break
if(flag):
    #print(2,p)
    #print(a1,b1,c1,a2,b2,c2)
    print("YES")
    sys.exit()
    
    

p=[P[0],pts[1]]
b1=p[0][0]-p[1][0]
a1=p[1][1]-p[0][1]
c1=-a1*p[0][0] - b1*p[0][1]
p=[]
a2=0
b2=0
c2=1
flag=True
for i in range(n):
    if(a1*pts[i][0]+b1*pts[i][1]+c1!=0 and a2*pts[i][0]+b2*pts[i][1]+c2!=0 ):
        p.append(pts[i])
        if(len(p)==2):
            
            b2=p[0][0]-p[1][0]
            a2=p[1][1]-p[0][1]
            c2=-a2*p[0][0] - b2*p[0][1]
        if(len(p)>2):
            
            flag=False
            break
if(flag):
    print("YES")
    #print(3,p)
    sys.exit()
print("NO")