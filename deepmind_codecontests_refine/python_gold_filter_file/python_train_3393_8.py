#! /usr/bin/env python3

n = int(input())
s = [input() for i in range(n)]

m = len(s[0])

a = 1488228228

for shift in range(m):
    t = s[0][shift:] + s[0][:shift]
    ans = 0
    for x in s:
        cur = None
        for i in range(m):
            if x == t:
                cur = i
                break
            x = x[1:] + x[:1]
        if cur is None:
            ans = None
            break
        else:
            ans += cur
    if ans is not None:
        a = min(a, ans)

if a == 1488228228:
    a = -1

print(a)
