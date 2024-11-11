from math import ceil
from collections import Counter

n, s = int(input()), list(input())
en = ord('a') + n - 1

for i in range(ceil(len(s) / 2)):
    if s[i] != '?' and s[-1 - i] != '?' and s[i] != s[-1 - i]:
        exit(print('IMPOSSIBLE'))
    elif s[i] != '?' and s[-1 - i] == '?':
        s[-1 - i] = s[i]
    elif s[-1 - i] != '?' and s[i] == '?':
        s[i] = s[-1 - i]

mem = Counter(s)

for i in range(ceil(len(s) / 2) - 1, -1, -1):
    if s[i] == '?' or s[-1 - i] == '?':
        for j in range(en, ord('a') - 1, -1):
            if not mem[chr(j)] or chr(j) == 'a':
                s[i] = s[-1 - i] = chr(j)
                if en > ord('a'):
                    en -= 1
                break
            en -= 1

# print(''.join(s))
print(''.join(s) if s == s[::-1] and len(set(s)) == n else 'IMPOSSIBLE')
