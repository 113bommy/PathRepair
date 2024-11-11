from time import time
try:
    start = time()

    fs, ss = input().split()

    fs = int(fs)
    ss = int(ss)
    field = [[0] * fs for i in range(fs)]

    for i in range(fs):
        inp = input()
        for j in range(fs):
            if(inp[j] == '#'):
                field[i][j] = -1

    for i in range(fs):
        for j in range(fs):
            d = 1
            r = 1
            for k in range(ss):
                if(i > fs - ss or field[i + k][j] == -1):
                    r = 0
                if(j > fs - ss or field[i][j + k] == -1):
                    d = 0
                if(r == 0 and d == 0):
                    break
            if(r == 1):
                for k in range(ss):
                    field[i + k][j] += 1
            if(d == 1):
                for k in range(ss):
                    field[i][j + k] += 1
    max = 0
    for i in range(fs):
        for j in range(fs):
            if(field[i][j] > max):
                max = field[i][j]
                maxi = i
                maxj = j

    print(maxi + 1, maxj + 1)
except:
    print(1,1)
