t=int(input())
for j in range(t):
    x,y,z=[int(x) for x in input().split()]
    if x==y and x==z:
        print("YES")
        print(x, y, z)
    elif x==y and z<x:
        print("YES")
        print(x, z, z)
    elif x==z and y<x:
        print("YES")
        print(y, x, y)
    elif y==z and x<z:
        print("YES")
        print(x, x, z)
    else:
        print("NO")