def read():
    s = input()
    l = len(s)
    r = [[0] * (l + 1), [0] * (l + 1)]
    for i in range(l):
        r[0][i + 1] = (r[0][i] + 1) * (s[i] == 'A')
        r[1][i + 1] = r[1][i] + (s[i] != 'A')
    return r
s, t = read(), read()
q = int(input())
r = ''
for i in range(q):
    a, b, c, d = map(int, input().split())
    sb = s[1][b] - s[1][a] + (s[0][a] == 0)
    sa = s[0][b] - (s[0][a] - 1) * (sb == 0)
    tb = t[1][d] - t[1][c] + (t[0][c] == 0)
    ta = t[0][d] - (t[0][c] - 1) * (tb == 0)
    if any([sb > tb, sa < ta, tb - sb & 1, sb == tb and (sa - ta) % 3, sa == ta and not sb and tb]):
        r += '0'
    else:
        r += '1'
print(r)
