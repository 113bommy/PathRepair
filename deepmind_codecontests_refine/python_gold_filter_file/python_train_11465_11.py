for n in range(int(input())):
    d=int(input())
    if d==1 or d==3 or d==2:
        print('N')
    else:

        a=(d*d-4*d)**.5
        x=(d+a)/2
        y=(d-a)/2
        print('Y',x,y)