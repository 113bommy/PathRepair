n, m = (int(_) for _ in input().split())
e = [set() for i in range(n + 1)]
deg = [0 for i in range(n + 1)]
for i in range(m):
    x, y = (int(_) for _ in input().split())
    deg[x] += 1
    deg[y] += 1
    e[x].add(y)
    e[y].add(x)
s = ['' for i in range(n + 1)]
ans = 2
for i in range(1, n + 1):
    if deg[i] == n - 1:
        s[i] = 'b'
for i in range(1, n + 1):
    if deg[i] != n - 1 and s[i] == '':
        s[i] = 'a' if ans == 2 else 'c'
        if ans == 2:
            for j in e[i]:
                if s[j] == '':
                    s[j] = 'a'
        elif ans == 1:
            for j in e[i]:
                if s[j] == 'a':
                    ans = -1
                elif s[j] == '':
                    s[j] = 'c'
        ans -= 1
for i in s[1:]:
    if i == '':
        ans = -1
if ans >= 0:
    for i in range(1, n + 1):
        for j in range(1 + i, n + 1):
            if (s[i] == 'a' and s[j] == 'c') or (s[i] == 'c' and s[j] == 'a'):
                if i in e[j] or j in e[i]:
                    ans = -1
            elif j not in e[i] or i not in e[j]:
                ans = -1
if ans >= 0:
    print('Yes')
    print(''.join(s[1:]))
else:
    print('No')
