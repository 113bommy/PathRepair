for _ in range(int(input())):
    x,y,z=map(int,input().split())
    if x==y or y==z or x==z:
        if x==y and x>=z:
            print("YES")
            print(x,z,z)
        elif x==z and x>=y:
            print("YES")
            print(y,z,y)
        elif y==z and y>=x:
            print("YES")
            print(x, x, y)
        else:
            print("NO")
    else:
        print("NO")