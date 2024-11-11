n=int(input())
l=[None]*n
i=0
while i<n:
    l[i]=input().split()
    i+=1
z=[int(px) for px in input().split()]
x=1
y=True
a=min(l[z[0]-1])
while x<n:
    u=l[z[x]-1][0]
    v=l[z[x]-1][1]
    if(u<a and v<a):
        y=False
        break
    elif(u>a and v>a):
        a=min(u,v)
    else:
        a=max(u,v)
    x+=1    
if(y):
    print("YES")
else:
    print("NO")