a = list(map(int, input().split()))
s = a[0] + a[1] + a[2] + a[3]
out = []
if s == 1:
    for i in range(4):
        if a[i] > 0:
            print('YES')
            print(i)
            exit()

for i in range(3):
    fst, snd = i, i+1
    if a[fst] == a[snd]:
        check = True
        for j in range(4):
            if j != fst and j != snd:
                if a[j] != 0:
                    check = False
        if check:
            out = [i, i+1] * a[fst]
            print('YES')
            print(' '.join(list(map(str, out))))
            exit()
    if a[fst] == a[snd] + 1:
        check = True
        for j in range(4):
            if j != fst and j != snd:
                if a[j] != 0:
                    check = False
        if check:
            out = [i, i+1] * a[snd] + [i]
            print('YES')
            print(' '.join(list(map(str, out))))
            exit()
    if a[fst] + 1 == a[snd]:
        check = True
        for j in range(4):
            if j != fst and j != snd:
                if a[j] != 0:
                    check = False
        if check:
            out = [i+1] + [i, i+1] * a[fst]
            print('YES')
            print(' '.join(list(map(str, out))))
            exit()
if a[1] < a[0]:
    print('NO')
    exit()
if a[2] < a[3]:
    print('NO')
    exit()

left = [0,1] * a[0]
right = [2,3] * a[3]

a[1] -= a[0]
a[2] -= a[3]

if a[1] == a[2] + 1:
    out = [1] + left + [2,1] * a[2] + right
    print('YES')
    print(' '.join(list(map(str, out))))
    exit()
if a[1] == a[2]:
    out = left + [2,1] * a[1] + right
    print('YES')
    print(' '.join(list(map(str, out))))
    exit()
if a[1] + 1 == a[2]:
    out = left + [2,1] * a[1] + right + [2]
    print('YES')
    print(' '.join(list(map(str, out))))
    exit()
print('NO')
exit()
