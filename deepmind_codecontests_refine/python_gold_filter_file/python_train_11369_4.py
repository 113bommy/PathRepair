s = input()
n = len(s)
a = []
ans = ''
for i in range(n-1):
    if s[i] == '<' and s[i+1] != '/':
        a.append(0)
    elif s[i] == '<' and s[i+1] == '/':
        a.append(1)
k = (2*n) // 7
t = 0
pos = 0
r = ' '
h = 0
for i in range(k):
    if a[i] == 0:
        t = 4
        h += 2
        ans += (h-2) * r + s[pos:pos + t - 1] + '\n'
    else:
        t = 5
        h -= 2
        ans += h * r + s[pos:pos + t - 1] + '\n'
    pos += t - 1
print(ans)
