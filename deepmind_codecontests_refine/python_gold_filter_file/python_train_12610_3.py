n = int(input())
L = [i for i in input()]
p = n//3
c0,c1,c2 = L.count('0'),L.count('1'),L.count('2')
if c0 == c1 and c1 == c2:
    print(''.join(L))
else:
    s = []
    for i in L:
        if i == '0':
            s.append('0')
        elif i == '1':
            if c0 < p and c1 > p:
                s.append('0')
                c0 += 1
                c1 -= 1
            else:
                s.append('1')
        else:
            if c0 < p and c2 > p:
                s.append('0')
                c0 += 1
                c2 -= 1
            elif c1 < p and c2 > p:
                s.append('1')
                c1 += 1
                c2 -= 1
            else:
                s.append('2')
    for i in reversed(range(n)):
        if L[i] == '0':
            if c0 > p and c2 < p:
                s[i] = '2'
                c0 -= 1
                c2 += 1
            elif c0 > p and c1 < p:
                s[i] = '1'
                c1 += 1
                c0 -= 1
        elif L[i] == '1':
            if c1 > p and c2 < p:
                s[i] = '2'
                c2 += 1
                c1 -= 1
    print(''.join(s))