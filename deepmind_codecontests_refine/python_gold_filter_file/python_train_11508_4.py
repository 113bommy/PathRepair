
n, d, h = map(int, input().split())

if d - h > h or (d == 1 and n > 2):
    print('-1')
else:
    for ver in range(2, h + 2):
        print('{} {}'.format(ver - 1, ver))

    prev = 1
    for ver in range(h + 2, h + 2 + (d - h)):
        print('{} {}'.format(prev, ver))
        prev = ver

    start = 1
    prev = max(prev, h + 1)
    if h == d:
        start = 2
    for ver in range(prev + 1, prev + 1 + (n - prev)):
        print('{} {}'.format(start, ver))
