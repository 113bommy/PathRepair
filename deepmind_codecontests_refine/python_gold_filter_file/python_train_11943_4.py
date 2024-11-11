n, p = map(int, input().split())
s = list(input())

bad = True
for i in range(n - p):
    if s[i] == s[i + p] == '.':
        s[i] = 0
        s[i + p] = 1

        bad = False

    elif s[i] == '.':
        s[i] = 1 - int(s[i + p])

        bad = False

    elif s[i + p] == '.':
        s[i + p] = 1 - int(s[i])

        bad = False

    elif s[i] != s[i + p]:
        bad = False

while '.' in s:
    s[s.index('.')] = 0

if bad:
    print('No')
    exit()

print(''.join(map(str, s)))
