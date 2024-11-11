n, x = input().split()
s = []
r = []
q = int(x)
c = 0
for i in range(int(n)):
    a, b = input().split()
    s.append(a)
    r.append(b)
for i in range(len(s)):
    if s[i] == '+':
        q += int(r[i])

    elif s[i] == '-':
        if int(r[i]) <= q:
            q -= int(r[i])
        else:
            c += 1


print(q, c)