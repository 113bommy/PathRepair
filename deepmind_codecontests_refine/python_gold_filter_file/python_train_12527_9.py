s = input()
v = s.split(sep='.')
flen = len(v[0])
llen = len(v[-1])
if len(v) < 2 :
        print('NO')
elif not (flen >= 1 and flen <= 8) :
        print('NO')
elif not (llen >= 1 and llen <= 3) :
        print('NO')
else :
        for i in v[1:-1] :
                if not (len(i) >= 2 and len(i) <= 11) :
                        print('NO')
                        exit()
        print('YES')
        print(v[0], end='')
        print('.', end='')
        for i in v[1:-1] :
                mi = min(3, len(i) - 1)
                print(i[0:mi])
                print(i[mi:len(i)], end = '')
                print('.', end = '')
        print(v[-1])
