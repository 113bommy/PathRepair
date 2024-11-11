a = input()
if 'h' in a:
    b = a[a.index('h'):]
    if 'e' in b:
        d = b[b.index('e'):]
        if 'i' in d:
            e = d[d.index('i'):]
            if 'd' in e:
                f = e[e.index('d'):]
                if 'i' in f:
                    print('YES')
                else:
                    print('NO')
            else:
                print('NO')
        else:
            print('NO')
    else:
        print('NO')
else:
    print('NO')