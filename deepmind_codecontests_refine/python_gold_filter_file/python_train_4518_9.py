a,b,n=map(int,input().split())
if a:
    if b/a>0:
        x=float(b/a)**(1/n)
        if a*int(x)**n==b:
            print(int(x))
        elif a*int(x+1)**n==b:
            print(int(x+1))
        else:
            print('No solution')
    elif b/a<0:
        if n%2:
            x=float(-b/a)**(1/n)
            if a*int(-x)**n==b:
                print(int(-x))
            elif a*int(-x-1)**n==b:
                print(int(-x-1))
            else:
                print('No solution')
        else:
            print('No solution')
    else:
        print(0)
else:
    print('No solution')if b else print(0)