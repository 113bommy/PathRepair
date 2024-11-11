def find(s, t):
    L = list(s)
    L.sort()
    if ('a' not in s) or ('b' not in s) or ('c' not in s):
        return ''.join(L)
    if t != 'abc':
        return ''.join(L)
    if L[-1] in ['a', 'b', 'c']:
        L.append('555')
    a = 0
    b = 0
    c = 0
    while L[0] == 'a':
        a += 1
        L.remove('a')
    while L[0] == 'b':
        b += 1
        L.remove('b')
    while L[0] == 'c':
        c += 1
        L.remove('c')

    if L[-1] == '555':
        L.pop()
        return 'a'*a + 'c'*c + 'b'*b + ''.join(L)

    return 'a'*a + 'c'*c + 'b'*b + ''.join(L)

cases = int(input())
for i in range(cases):
    s = input()
    t = input()
    print(find(s, t))