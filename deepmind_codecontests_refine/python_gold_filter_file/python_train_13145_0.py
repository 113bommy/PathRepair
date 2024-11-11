for _ in range(int(input())):
    x, y = map(int, input().split())
    c = list(map(int, input().split()))
    for i in range(6):
        c[i] = min(c[i], c[(i + 1) % 6] + c[(i - 1) % 6])
    if x >= 0:
        if y >= x:
            print(x * c[0] + (y - x) * c[1])
        elif y <= 0:
            print(x * c[5] + abs(y) * c[4])
        else:
            print((x - y) * c[5] + y * c[0])
    else:
        if y <= x:
            print((x - y) * c[4] + abs(x) * c[3])
        elif y >= 0:
            print(abs(x) * c[2] + y * c[1])
        else:
            print(abs(y) * c[3] + (y - x) * c[2])
    
    # path1=abs(x)*c[0 if x>=0 else 3]+abs(y-x)*c[1 if y-x>=0 else 4]
    # path2=abs(y)*c[0 if y>=0 else 3]+abs(x-y)*c[5 if x-y>=0 else 2]
    # path3=abs(y)*c[1 if y>=0 else 4]+abs(x)*c[5 if x>=0 else 2]
    
    # print(min(path1,path2,path3))
