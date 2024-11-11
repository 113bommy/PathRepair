for _ in range(int(input())):
    a, b, c = map(int, input().split())
    if(c-a*b >= 0):
        y = -1
        x = 1
    elif(a-c>=0):
        x = -1
        y = 2
    else:    
        y = b
        x = 1
    print(x, y)    