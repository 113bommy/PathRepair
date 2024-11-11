for _ in range(int(input())):
    x,y=map(int,input().split())
    a,b=map(int,input().split())
    s=a+a
    if x+y==0:
        print(0)
        continue
    if s<=b:
        print(a*(x+y))
    else:
        if x>=y:
            print(b*y+(x-y)*a)
        if y>x:
            print(x*b+(y-x)*a)
    
        
            
        
