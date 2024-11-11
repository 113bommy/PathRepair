n, m = map(int, input().split())
s = [input() for _ in range(n)]
s += [''.join(p) for p in zip(*s)]

possible = all('WS' not in p and 'SW' not in p for p in s)

print(('No', 'Yes')[possible])

if possible:
    s = [['#'] * (m + 2)] + [['#'] + list(p) + ['#'] for p in s[:n]] + [['#'] * (m + 2)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s[i][j] == '.' and 'W' in {s[i][j - 1], s[i][j + 1], s[i - 1][j], s[i + 1][j]}:
                s[i][j] = 'D'

    print('\n'.join([''.join(s[i][1: m + 1]) for i in range(1, n + 1)]))
