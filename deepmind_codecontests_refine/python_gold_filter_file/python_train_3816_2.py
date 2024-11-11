import re
cat = r'(WS)|(SW)'
n, k = map(int, input().split())
f = False
d = []
prev = 'i' * k
for _ in range(n):
    l = input()
    if re.search(cat, l):
        f = True
    l = l.replace('.','D')
    d.append(l)
    start = 0
    for _ in range(l.count('S')):
        if prev[l.index('S', start)] == 'W':
            f = True
            break
        start = l.index('S',start) + 1
    start = 0
    for _ in range(l.count('W')):
        if prev[l.index('W', start)] == 'S':
            f = True
            break
        start = l.index('W',start)+1
    prev = l
if f:
    print('No')
else:
    print('Yes')
    for i in d:
        print(i)