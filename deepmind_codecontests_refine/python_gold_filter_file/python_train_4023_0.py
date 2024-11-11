n = int(input())
S = set('abcdefghijklmnopqrstuvwxyz')
lines = [input().strip() for _ in range(n)]
ok, cnt = 0, 0
for line in lines[:-1]:
    c, s = line.split()
    if ok:
        if c == '!' or c == '?':
            cnt += 1
        continue
    if '!' == c:
        S &= set(s)
    elif '.' == c:
        S -= set(s)
    elif '?' == c:
        S -= set(s)
    if len(S) == 1:
        ok = 1
print(cnt)