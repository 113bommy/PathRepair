h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
d_al = dict()
for ai in a:
    for aij in ai:
        if aij in d_al:
            d_al[aij] += 1
        else:
            d_al[aij] = 1
od = 0
a2 = 0
for i in d_al.values():
    if i % 2 == 1:
        od += 1
    elif i % 4 == 2:
        a2 += 1
if h % 2 == 1 and w % 2 == 1:
    if od == 1 and a2 <= (h + w - 1) // 2:
        print('Yes')
    else:
        print('No')
elif h % 2 == 1:
    if od == 0 and a2 <= w // 2:
        print('Yes')
    else:
        print('No')
elif w % 2 == 1:
    if od == 0 and a2 <= h // 2:
        print('Yes')
    else:
        print('No')
else:
    if od == 0 and a2 == 0:
        print('Yes')
    else:
        print('No')
