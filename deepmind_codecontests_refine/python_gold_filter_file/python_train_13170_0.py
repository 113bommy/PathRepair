a, t = input(), input() + ' '
b = a[::-1]
s, p = '', []
for q in t:
    d = s
    s += q
    if s in a or s in b: continue
    if d in a:
        k = a.find(d)
        p += [(k + 1, k + len(d))]
    elif d in b:
        k = b.rfind(d)
        p += [(len(a) - k, len(a) - k - len(d) + 1)]
    else:
        print(-1)
        exit()
    s = q
print(len(p))
for i, j in p: print(i, j)