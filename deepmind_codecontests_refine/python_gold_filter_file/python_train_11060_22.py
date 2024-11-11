t = int(input())
for _ in range(t):
    n = int(input())
    arrayeven = [i for i in range(2, n+1, 2)]
    arraynoteven = [i for i in range(1, n, 2)]
    del arraynoteven[-1]
    SumEven = sum(arrayeven)
    SumNotEven = sum(arraynoteven)
    k = 1
    while SumEven != SumNotEven + k:
        if SumNotEven + k >= SumEven:
            print('NO')
            break
        k += 2
    else:
        arraynoteven.append(k)
        print('YES')
        print(*arrayeven + arraynoteven)