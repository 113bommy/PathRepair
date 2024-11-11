q = int(input())
for _ in range(q):
    n = int(input())
    s = ''
    while n > 0:
        s = str(n % 3) + s
        n = n // 3
    leng = len(s)
    ind_2 = s.find('2')
    fl = 1
    fl_1 = 1
    if ind_2 == -1:
        fl = 0
        fl_1 = 0
        qqq = s
    while fl:
        ind_1 = s.rfind('1', 0, ind_2)
        if (ind_2 - ind_1 > 1) or ind_1 == -1:
            fl = 0
        else:
            ind_2 = ind_1
    if fl_1:
        qqq = s[0:max(ind_2-1, 0)] + "1" + "0"*(leng-ind_2)
    print(int(qqq, 3))
