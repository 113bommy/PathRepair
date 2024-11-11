while True:
    try:
        line=input()

    except:
        break

    a,b,c,d,e,f=map(int, line.strip().split())

   
    
    y=(c*d-f*a)/(b*d-a*e)
    x=(c*e-f*b)/(a*e-b*d)

    if x<=0 and x>=-0.0005:
        x=0.000
    
    if y<=0 and y>=-0.0005:
        y=0.000
        
    print('{:.3f} {:.3f}'.format(x,y))
    
    