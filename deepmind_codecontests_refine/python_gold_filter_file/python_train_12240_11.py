n, m, k = map(int, input().split())
l, d = 0, 0
g = 2*m

if k % g == 0:
    l = k // g
else:
    l = k // g + 1

c = k % g
if c == 0:
    d = m
else:
    if c % 2 == 0:
        d = c // 2
    else:
        d = c // 2 + 1

if k % 2 == 0:
    print(l, d, 'R')
else:
    print(l, d, 'L')    