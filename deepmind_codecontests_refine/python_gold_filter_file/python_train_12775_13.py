v = list(enumerate(map(int, input().split())))
v.sort(key = lambda x:x[1])
v = [[a,b] for a,b in v]
print(50, 50)

ss = [['.']* 50 for _ in range(50)]

re_at = 0
while v[0][1] > 1 and re_at < 25:
    for i, (a, r) in enumerate(v[:3]):
        ch = ['A', 'B', 'C', 'D'][a]
        if i == 0:
            ss[0][2 * re_at + 1] = ch
        elif i == 1:
            ss[0][2 * re_at] = ch
        elif i == 2:
            ss[1][2 * re_at + 1] = ch
    v[0][1], v[1][1], v[2][1] = v[0][1]-1, v[1][1]-1, v[2][1] - 1 
    re_at += 1
if re_at > 0 and re_at < 25:
    ss[0][2 * re_at] = ['A', 'B', 'C', 'D'][v[3][0]]
    v[3][1] -= 1

re_at = 0
while v[0][1] > 1 and re_at < 25:
    for i, (a, r) in enumerate(v):
        if i == 1:
            continue
        ch = ['A', 'B', 'C', 'D'][a]
        if i == 0:
            ss[49][2 * re_at + 1] = ch
        elif i == 2:
            ss[49][2 * re_at] = ch
        elif i == 3:
            ss[48][2 * re_at + 1] = ch
    v[0][1], v[3][1], v[2][1] = v[0][1]-1, v[3][1]-1, v[2][1] - 1 
    re_at += 1
if re_at > 0 and re_at < 25:
    ss[49][2 * re_at] = ['A', 'B', 'C', 'D'][v[3][0]]
    v[3][1] -= 1

re_at = 0
while v[0][1] > 1 and re_at < 25:
    for i, (a, r) in enumerate(v[:2]):
        ch = ['A', 'B', 'C', 'D'][a]
        if i == 0:
            ss[48][2 * re_at] = ch
        elif i == 1:
            ss[47][2 * re_at] = ch
    v[0][1], v[1][1] = v[0][1]-1, v[1][1]-1 
    re_at += 1

re_at = 0
while v[0][1] > 1 and re_at < 25:
    for i, (a, r) in enumerate(v[:3]):
        if i == 1:
            continue
        ch = ['A', 'B', 'C', 'D'][a]
        if i == 0:
            ss[47][2 * re_at+1] = ch
        elif i == 2:
            ss[46][2 * re_at + 1] = ch
    v[0][1], v[2][1] = v[0][1]-1, v[2][1]-1 
    re_at += 1

for a, r in v[1:]:
    re_at = 0

    row = [4, 5, 7, 8, 10]
    ch = ['A', 'B', 'C', 'D'][a]
    row_at = 0
    while row_at < 5 and re_at < r:
        sc1 = 10 * a + row[row_at]
        
        i = 0
        sc2 = 3 + (1 if row_at in [1, 3] else 0)
        while i < 22 and re_at < r:
            ss[sc1][sc2] = ch
            sc2 += 2
            i += 1
            re_at += 1

        row_at += 1

ch = ['A', 'B', 'C', 'D'][v[0][0]]
for ss1 in ss:
    ss2 = ''.join(ss1)
    ss2 = ss2.replace('.',ch)
    print(ss2)