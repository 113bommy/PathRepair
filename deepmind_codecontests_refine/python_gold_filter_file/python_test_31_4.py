t = int(input())
for _ in range(t):
    n = int(input())
    mass = list(map(int, input().split()))
    mass1 = [1 for _ in range(n)]
    if len(mass) % 2 == 0:
        for i in range(1, len(mass), 2):
            mass1[i-1] = -mass[i]
            mass1[i] = mass[i-1]
    else:
        for i in range(1, len(mass)-3, 2):
            mass1[i-1] = -mass[i]
            mass1[i] = mass[i-1]
        # strr = sorted(mass[n - 3:])
        strrr = mass[n-3:]
        plus = []
        minus = []
        # print(strr)
        # if strr[0] < 0 and strr[1] < 0:
        #     mass1[mass.index(strr[0])] = -strr[-1]
        #     mass1[mass.index(strr[1])] = -strr[-1]
        #     mass1[mass.index(strr[-1])] = strr[0] + strr[1]
        # else:
        #     mass1[mass.index(strr[1])] = -strr[0]
        #     mass1[mass.index(strr[-1])] = -strr[0]
        #     mass1[mass.index(strr[0])] = strr[1] + strr[-1]
        for i in range(len(strrr)):
            if strrr[i] > 0:
                plus.append(i+n-3)
            else:
                minus.append(i +n-3)
        if len(minus) == 0:
            minus.append(plus[0])
            del plus[0]
        elif len(plus) == 0:
            plus.append(minus[0])
            del minus[0]
        # print(plus, minus)
        if len(plus) > len(minus):
            mass1[plus[0]] = -mass[minus[0]]
            mass1[plus[1]] = -mass[minus[0]]
            mass1[minus[0]] = mass[plus[0]] + mass[plus[1]]
        else:
            mass1[minus[0]] = -mass[plus[0]]
            mass1[minus[1]] = -mass[plus[0]]
            mass1[plus[0]] = mass[minus[0]] + mass[minus[1]]
    print(*mass1)