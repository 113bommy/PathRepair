# -*- coding: utf-8 -*-


s = input()
if not('AB' in s):
    print('NO')
else:
    if not ('BA' in s.replace('AB', ' ', 1)):
        if 'BA' in s:
            if not ('AB' in s.replace('BA', ' ', 1)):
                print('NO')
            else:
                print('YES')
        else:
            print('NO')
    else:
        print('YES')
