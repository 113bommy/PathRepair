s = input()
c = s.split('=')
l = c[0].count('|')
r = c[1].count('|')
# print(l, r)
if l == r:
    print(s)
elif r == l + 2:
    print('|' + s[:-1])
elif r + 2 == l:
    d = c[0].split('+')
    if len(d[0]) == 1:
        print(s[:2] + s[3:] + '|')
    else:
        print(s[1:] + '|')
else:
    print('Impossible')
