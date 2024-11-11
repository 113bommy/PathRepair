for i in range (int(input())):
    data = [int(i) for i in input().split()]
    a = data[0]
    b = data[1]
    c = data[2]
    d = data[3]
    k = data[4]
    x,y = 0,0
    while c * x < a:
        x += 1
    while d * y < b:
        y += 1
    if x + y <= k:
        print(x,y)
    else:
        print(-1)
