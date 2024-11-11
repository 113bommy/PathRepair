s = list(input())
t = list()
u = list()
d = dict()
var = 97
for i in range(26):
    d[chr(var + i)] = 0
for i in s:
    d[i] += 1
i = 0
while i < len(s):
    if d[chr(var)] > 0:
        while i < len(s):
            d[s[i]] -= 1
            t.append(s[i])
            i += 1
            if t[-1] <= chr(var):
                u.append(t.pop())
                break
    else:
        var += 1
        while t and t[-1] <= chr(var):
            u.append(t.pop())


while t != []:
    u.append(t.pop())

print("".join(u))
