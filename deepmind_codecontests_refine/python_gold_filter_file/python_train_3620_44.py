import sys
input = sys.stdin.readline

du = {}
dd = {}
dr = {}
dl = {}
n = int(input())

p = {'U': {}, 'D': {}, 'R': {}, 'L': {}}
m = {'U': {}, 'D': {}, 'R': {}, 'L': {}}

for i in range(n):
    x, y, u = input().rstrip('\n').split()
    x = int(x)
    y = int(y)
    if x + y in p[u]:
        p[u][x+y].append(x)
    else:
        p[u][x+y] = [x]

    if x - y in m[u]:
        m[u][x-y].append(x)
    else:
        m[u][x-y] = [x]
    
    if u == 'U':
        if x in du:
            du[x].append(y)
        else:
            du[x] = [y]
    if u == 'D':
        if x in dd:
            dd[x].append(y)
        else:
            dd[x] = [y]
    if u == 'R':
        if y in dr:
            dr[y].append(x)
        else:
            dr[y] = [x]
    if u == 'L':
        if y in dl:
            dl[y].append(x)
        else:
            dl[y] = [x]

for key in p:
    for key2 in p[key]:
        if key == 'U' or key == 'R':
            p[key][key2].sort(reverse=True)
        else:
            p[key][key2].sort()

for key in m:
    for key2 in m[key]:
        if key == 'D' or key == 'R':
            m[key][key2].sort(reverse=True)
        else:
            m[key][key2].sort()

ans = 10 ** 7

for key in p['U']:
    if key not in p['R']:
        continue
    num = len(p['R'][key])
    i = 0
    for x in p['U'][key]:
        while x < p['R'][key][i]:
            if i == num - 1:
                break
            i += 1
        if x > p['R'][key][i]:
            ans = min(ans, (x - p['R'][key][i]) * 10)

for key in m['D']:
    if key not in m['R']:
        continue
    num = len(m['R'][key])
    i = 0
    for x in m['D'][key]:
        while x < m['R'][key][i]:
            if i == num - 1:
                break
            i += 1
        if x > m['R'][key][i]:
            ans = min(ans, (x - m['R'][key][i]) * 10)

for key in m['U']:
    if key not in m['L']:
        continue
    num = len(m['L'][key])
    i = 0
    for x in m['U'][key]:
        while x > m['L'][key][i]:
            if i == num - 1:
                break
            i += 1
        if x < m['L'][key][i]:
            ans = min(ans, (m['L'][key][i] - x) * 10)

for key in p['D']:
    if key not in p['L']:
        continue
    num = len(p['L'][key])
    i = 0
    for x in p['D'][key]:
        while x > p['L'][key][i]:
            if i == num - 1:
                break
            i += 1
        if x < p['L'][key][i]:
            ans = min(ans, (p['L'][key][i] - x) * 10)

for x in du:
    if x in dd:
        du[x].sort()
        dd[x].sort()
        m = len(dd[x])
        i = 0
        for yi in du[x]:
            while yi > dd[x][i]:
                if i == m - 1:
                    break
                i += 1
            if yi <= dd[x][i]:
                ans = min(ans, (dd[x][i] - yi) * 5)

for y in dr:
    if y in dl:
        dr[y].sort()
        dl[y].sort()
        m = len(dl[y])
        i = 0
        for xi in dr[y]:
            while xi > dl[y][i]:
                if i == m - 1:
                    break
                i += 1
            if xi <= dl[y][i]:
                ans = min(ans, (dl[y][i] - xi) * 5)

if ans == 10 ** 7:
    print('SAFE')
else:
    print(ans)

