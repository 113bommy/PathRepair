n, m = map(int, input().split())
a = [ [ '.' for j in range(m) ] for i in range(n) ]

for i in range(0, len(a)):
    if i % 2 == 0:
        a[i] = ['#'] * m
    elif i % 4 == 1:
        a[i][-1] = '#'
    else:
        a[i][0] = '#'

s = ''
for i in range(0, len(a)):
    s += ''.join(a[i]) + '\n'

print(s)