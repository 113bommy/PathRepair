n = input()
i = k = o = 0
if n.count('2') == 0 and n.count('3') == 0 and n.count('5') == 0 and n.count('6') == 0 and n.count('7') == 0 and n.count('8') == 0 and n.count('9') == 0 and n.count('0') == 0 and n[0] != '4':
    while i < (len(n)) and o == 0:
        if n[i] == '4': k += 1
        else: k = 0
        if k > 2:
            print('NO')
            o += 1
        i += 1
    if o == 0: print('YES')
else: print('NO')