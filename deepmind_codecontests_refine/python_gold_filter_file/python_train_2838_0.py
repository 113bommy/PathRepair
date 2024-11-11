for t in range(int(input())):
    x,y,z=(map(int,input().split()))
    if x==y==z:
        print('YES')
        print(x,y,z)
        continue
    elif (x==z and y<x) :
        print('YES')
        print(y,y,x)
    elif  (y==z and x<y)  :
        print('YES')
        print(x,x,y)
    elif (x==y) and z<x:
        print('YES')
        print(z,z,y)
    else:
        print('NO')