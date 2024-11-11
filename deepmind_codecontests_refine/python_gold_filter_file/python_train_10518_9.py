while True:
    m, f, r = list(map(int,input().split()))
    if (m == -1) & (f == -1) & (r == -1):
        break
    if (m + f) < 30 or m == -1 or f == -1:
        print("F")
    elif (m + f) < 50 and r < 50:
        print("D")
    elif (m + f) < 65:
        print("C")
    elif (m + f) < 80:
        print("B")
    else:
        print("A")