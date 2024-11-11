s = [0] * 86
for c in input():
    s[ord(c)] += 1
h, v = (s[76], s[82]), (s[85], s[68])
print(-1 if sum(s) & 1 else (max(h) + max(v) - min(h) - min(v)) // 2)