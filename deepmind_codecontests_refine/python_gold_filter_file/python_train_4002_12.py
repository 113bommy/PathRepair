s = input()
flag = 0
if len(s) >= 5:
    for i in s:
        if ord(i) >= ord('A') and ord(i) <= ord('Z'):
            break
    else:
        flag += 1
    for i in s:
        if ord(i) >= ord('a') and ord(i) <= ord('z'):
            break
    else:
        flag += 1
    for i in s:
        if i in '0123456789':
            break
    else:
        flag += 1
else:
    flag += 1
if flag == 0:
    print('Correct')
else:
    print('Too weak')
    