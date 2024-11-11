t=int(input())
i=0

while i < t:
    string=input()
    x,y,n=string.split()
    x=int(x)
    y=int(y)
    n=int(n)
    k=n%x
    if k < y:
        n=n-(k+x)+y
    else:
        n=n-(k-y)
    
    print(n)    
    i+=1
