a=int(input())
bt=1
b=[int(i) for i in input().split()]
for i in range(len(b)):
    c=0
    for j in range(len(b)-i):
        if b[j]>b[c]:
            c=j
    t=b[len(b)-1-i]
    b[len(b)-1-i]=b[c]
    b[c]=t
r=b[0]
h=1
p=1
for i in range(1,a):
    if b[i]==r:
        h+=1
        if h>bt:
            bt=h
    else:
        h=1
        r=b[i]
        p+=1
print(bt,p,end=" ")
            
    
    
    
        
