s = input()
e = input()
a = 'qwertyuiop'
b = 'asdfghjkl;'
c = 'zxcvbnm,./'
for i in range(len(e)):
    if e[i] in a and s == 'R':
        print(a[a.index(e[i]) - 1], end='')
    elif e[i] in a and s == 'L':
        print(a[a.index(e[i]) + 1], end='')
    elif e[i] in b and s == 'R':
        print(b[b.index(e[i]) - 1], end='')
    elif e[i] in b and s == 'L':
        print(b[b.index(e[i]) + 1], end='')
    elif e[i] in c and s == 'R':
        print(c[c.index(e[i]) - 1], end='')
    elif e[i] in c and s == 'L':
        print(c[c.index(e[i]) + 1], end='')