def mk_table(n):
    res = [1] * (n + 1)
    res[:2] = 0, 0

    for i in range(2, n):
        if i ** 2 > n:
            break

        if res[i] == 1:
            for j in range(i*2, n + 1, i):
                res[j] = 0

    return res


tbl = mk_table(999999)
try:
    while 1:
        print(len([x for x in tbl[:int(input())+1] if x == 1]))
except Exception:
    pass