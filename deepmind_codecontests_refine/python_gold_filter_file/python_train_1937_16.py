n=int(input())
l=list(map(int,input().split()))
l=sorted(l)
x,y,z=l[0],l[1],l[2]
if x<y<z:
    print(l.count(z))
if x<y and y==z:
    c=l.count(y)
    print((c*(c-1))//2)
if  x==y and y<z:
    print(l.count(z))
if x==y and y==z:
    c=l.count(x)
    ans=c*(c-1)*(c-2)
    print(ans//6)
    
    
    
    