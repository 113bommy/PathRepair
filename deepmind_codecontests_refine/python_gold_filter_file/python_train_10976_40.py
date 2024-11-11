#!/bin/python3
z=list(map(int,input().split()))
y=list(map(int,input().split()))
q=[]
l=[]
u=[]
h=[]
k=[]
x=[]
n=[]
c=0
if z[1] <= 5:
    if len(y)!=z[0]:
        print("is wrong")
    else:
        for i in y:
            if i<5:
                q.append(5-i)
    for r in q:
        if z[1]==5 and r==5:
            l.append(r)
        if z[1]==4 and r>=4:
            u.append(r)
        if z[1]==3 and r>=3:
            h.append(r)
        if z[1]==2 and r>=2:
            k.append(r)
       
        if z[1]==1 :
            n.append(r)

if len(k)>=3:
    print(int(len(k)/3))
elif len(l)>=3 and len(l):
     print(int(len(l)/3))
elif len(u)>=3:
     print(int(len(u)/3))
elif len(h)>=3:
    print(int(len(h)/3))
elif len(n)>=3:
    print(int(len(n)/3))
else:
    print(0)






     
                
    
        


