def r(t=int):
    return list(map(t, input().split()))


def ri(t=int):
    return t(input())


def cd(it):
    ret_val = dict()
    for v in it:
        ret_val[v] = ret_val.get(v, 0) + 1
    return ret_val


for h in range(ri()):
    nn = ri()
    n = nn
    while n > 6:
        print(n, end=' ')
        n -= 2

    if n == 6:
        print('6 2 4 1 3 5', end=' ')
        n = 7
    elif n == 5:
        print('5 3 1 4 2', end=' ')
        n = 6
    elif n == 4:
        print('3 1 4 2', end=' ')
    else:
        print('-1', end=' ')

    while n < nn:
        print(n, end=' ')
        n += 2
    print()
