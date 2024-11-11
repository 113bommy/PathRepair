a, b = map(int, input().split())
if a == 1 and b == 1:
    print(0)
else:
    o1 = 0
    o2 = 0
    i1 = []
    i2 = []
    if a < b:
        i1.append(1)
        o1 = 1
    else:
        i2.append(1)
        o2 = 1        
    for i in range(2, a + b + 1):
        if (o1 < a):
            o1 += 1
            i1.append(i)
        else:
            o2 += 1
            i2.append(i)
    for i in range(a):
        for j in range(b):
            print(i1[i] * i2[j], end = " ")
        print()