def erase(n, rem, count):
    cnt = 0
    i = len(n) - 1
    s = n
    while i >= 0 and cnt < count:
        if int(s[i]) % 3 == rem:
            cnt += 1
            s = s[:i] + s[i + 1:]
        i -= 1
    if cnt != count:
        return ""
    while len(s) > 1 and s[0] == '0':
        s = s[1:]
    return s

n = input()

a = 0
for x in range(len(n)):
    a += int(n[x])
    a %= 3

if a == 0:
    print(n)
else:
    n1 = erase(n, a, 1)
    n2 = erase(n, 3 - a, 2)
    if len(n1) == 0 and len(n2) == 0:
        print(-1)
    elif len(n1) > len(n2):
        print(n1)
    else:
        print(n2)
