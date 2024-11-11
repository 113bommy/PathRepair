input()
a = list(map(int, input().split(' ')))
k = 0
while len(a) > 0:
    b = a.index(max(a))
    try:
        if abs(a[b] - a[b+1]) >= 2:
            k = 1
            break
    except IndexError:
        pass
    try:
        if abs(a[b] - a[abs(b-1)]) >= 2:
            k = 1
            break
    except IndexError:
        pass
    a.pop(b)
if k == 1:
    print('NO')
else: 
    print('YES')