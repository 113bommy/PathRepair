g = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]

while True :
    try :
        c = -1
        left, right = int(input()), []
        while True :
            if left <= 0 : break
            else :
                if left - g[c] < 0 : c += -1
                else :
                    left -= g[c]
                    right.append(g[c])
        right.sort()
        print(*right)
    except : break