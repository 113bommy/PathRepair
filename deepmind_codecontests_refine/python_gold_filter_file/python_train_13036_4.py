for q in range(int(input())):
    x = list(map(int, input().split()))
    g = sorted(x, reverse=True)
    s = 0
    if g[0] == 0: print(0)
    elif g[0] == 1 or (g[0] > 1 and (g[1] == 1 or g[1] == 0)): 
        for i in range(3):
            if g[i] >= 1:
                s = s + 1
        print(s)
    elif g[0] == 2 and g[2] == 2: print(4)
    elif g[2] >= 4: print(7)
    elif g[2] == 3: print(6)
    elif g[0] == 2 and g[1] == 1: print(2+g[2])
    elif g[0] == 2 and g[1] == 2: print(3 + g[2])
    elif g[0] == 3 and g[2] == 2: print(5)
    elif g[0] == 3 and g[1] >= 2: print(3+g[2])
    elif g[0] == 3 and g[1] == 1: print(2+g[2])
    elif g[0] >= 4 and g[2] == 2: print(5)
    elif g[0] >= 4 and g[1] >= 2: print(3+g[2])  
    elif g[0] >= 4: print(1+g[1]+g[2])

