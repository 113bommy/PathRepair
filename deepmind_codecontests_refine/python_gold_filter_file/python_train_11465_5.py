for i in ' '*int(input()):
    n=int(input())
    if 0<n<4:print('N')
    else:
        a=(n+(n**2-4*n)**0.5)/2
        b=n-a
        print('Y',a,b)