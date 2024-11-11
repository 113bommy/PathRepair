
t = input()
for i in t:
    if i == 'H'or i == 'Q' or i == '9':
        print('YES')
        t = ''
        break
if t != '':
    print('NO')