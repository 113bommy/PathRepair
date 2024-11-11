while True:
    try:
        a,b,c,d,e,f = map(int, input().split())
        g = (a*e - b*d) 
        x = (c*e - b*f)
        y = (a*f - c*d)
        print('{0:.3f}'.format(x/g+0.0001) +' {0:.3f}'.format(y/g +0.0001))
              
    except EOFError: break
