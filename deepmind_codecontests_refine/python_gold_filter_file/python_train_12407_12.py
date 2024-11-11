def flip(s, i):
    if s[i] == '1':
        s[i] = '0'
    else:
        s[i] = '1'
    return s
n = int(input())
s = input()
s = list(s)
l = []
for _ in range(n):
    a, b = map(int, input().split())
    l.append((a, b))
ans = s.count('1')
for i in range(1, 125):
    for j in range(n):
        if i >= l[j][1] and i % l[j][0] == l[j][1] % l[j][0]:
            s = flip(s, j)
    ans = max(ans, s.count('1'))
print(ans)