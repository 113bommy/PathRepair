import sys
import math
#input = sys.stdin.readline
imp = 'IMPOSSIBLE'


t = int(input())

for test in range(t):
    n, m = list(map(int, input().split(" ")))
    xx = list(map(int, input().split(" ")))
    sorx = sorted(enumerate(xx), key=lambda z: z[1])
    porx = [i[0] for i in sorx]
    invpor = [i[0] for i in sorted(enumerate(porx), key=lambda z: z[1])]
    x = [i[1] for i in sorx]
    res = ['' for i in range(n)]
    ss = input().split(" ")
    if test != t - 1:
        ss[-1] = ss[-1][0]
    s = [ss[i[0]] for i in sorx]
    lastl1 = -1
    lastl2 = -1
    pairs = []
    r1 = []
    r2 = []
    #if test == t - 1:
    #    print(porx)
    #    print(invpor)
    #    print(x)
    #    print(s)
    for i in range(n):
        if x[i] % 2 == 1:
            if s[i] == 'L':
                if r1:
                    rr = r1.pop()
                    pairs.append([rr, i])
                elif lastl1 == -1:
                    lastl1 = i
                else:
                    pairs.append([lastl1, i])
                    lastl1 = -1
            else:
                r1.append(i)
        else:
            if s[i] == 'L':
                if r2:
                    rr = r2.pop()
                    pairs.append([rr, i])
                elif lastl2 == -1:
                    lastl2 = i
                else:
                    pairs.append([lastl2, i])
                    lastl2 = -1
            else:
                r2.append(i)
    lastr1 = -1
    lastr2 = -1
    #print(pairs)
    while r1:
        if lastr1 == -1:
            lastr1 = r1.pop()
        else:
            rr = r1.pop()
            pairs.append([lastr1, rr])
            lastr1 = -1
    #print(pairs)
    while r2:
        if lastr2 == -1:
            lastr2 = r2.pop()
        else:
            rr = r2.pop()
            pairs.append([lastr2, rr])
            lastr2 = -1
    #print(pairs)
    if lastr1 > -1 and (lastl1 > -1):
        pairs.append([lastl1, lastr1])
        lastl1 = -1
        lastr1 = -1
    elif lastl1 > -1:
        res[lastl1] = '-1'
    elif lastr1 > -1:
        res[lastr1] = '-1'
    if lastr2 > -1 and (lastl2 > -1):
        pairs.append([lastl2, lastr2])
        lastl2 = -1
        lastr2 = -1
    elif lastl2 > -1:
        res[lastl2] = '-1'
    elif lastr2 > -1:
        res[lastr2] = '-1'
    #print(res)
    #print(pairs)
    #print(s)
    for pair in pairs:
        if s[pair[0]] == 'L':
            if s[pair[1]] == 'L':
                res[pair[0]] = str((x[pair[0]] + x[pair[1]]) // 2)
                res[pair[1]] = str((x[pair[0]] + x[pair[1]]) // 2)
            else:
                if x[pair[0]] > x[pair[1]]:
                    res[pair[0]] = str((x[pair[0]] - x[pair[1]]) // 2)
                    res[pair[1]] = str((x[pair[0]] - x[pair[1]]) // 2)
                else:
                    res[pair[0]] = str((x[pair[0]] + 2 * m - x[pair[1]]) // 2)
                    res[pair[1]] = str((x[pair[0]] + 2 * m - x[pair[1]]) // 2)
        else:
            if s[pair[1]] == 'R':
                res[pair[0]] = str((2 * m - x[pair[0]] - x[pair[1]]) // 2)
                res[pair[1]] = str((2 * m - x[pair[0]] - x[pair[1]]) // 2)
            else:
                if x[pair[0]] < x[pair[1]]:
                    res[pair[0]] = str((x[pair[1]] - x[pair[0]]) // 2)
                    res[pair[1]] = str((x[pair[1]] - x[pair[0]]) // 2)
                else:
                    res[pair[0]] = str((x[pair[1]] + 2 * m - x[pair[0]]) // 2)
                    res[pair[1]] = str((x[pair[1]] + 2 * m - x[pair[0]]) // 2)
    #print(invpor)
    resres = [res[i] for i in invpor]
    print(' '.join(resres))
