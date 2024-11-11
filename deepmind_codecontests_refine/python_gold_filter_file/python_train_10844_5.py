n = int(input())
for l in range(n):
    x = input()
    y = input()
    x1, y1, x2, y2, x3, y3 = [], [], 1, 1, [], []
    lol = 1
    x1.append(x[0])
    y1.append(y[0])
    for i in range(1, len(x)):
        if x[i] == x[i - 1]:
            x2 += 1
        else:
            x3.append(x2)
            x1.append(x[i])
            x2 = 1
    x3.append(x2)
    for i in range(1, len(y)):
        if y[i] == y[i - 1]:
            y2 += 1
        else:
            y3.append(y2)
            y1.append(y[i])
            y2 = 1
    y3.append(y2)
    # print(x1, y1)
    if len(x1) != len(y1):
        print("NO")
        lol = 0
    else:
        for i in range(len(x1)):
            if x1[i] == y1[i]:
                if x3[i] > y3[i]:
                    print("NO")
                    lol = 0
                    break
            else:
                print("NO")
                lol = 0
                break
        if lol:
            print("YES")


