n=int(input())
c=0
while n!=0:
    r=n//100
    c=c+(r)
    n=n-(r*100)
    
    r=n//20
    c=c+r
    n=n-(r*20)
    
    r=n//10
    c=c+r
    n=n-(r*10)
    
    r=n//5
    c=c+r
    n=n-(r*5)
    
    r=n//1
    c=c+r
    n=n-(r*1)
print(c)