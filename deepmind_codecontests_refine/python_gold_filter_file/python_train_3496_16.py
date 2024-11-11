s, k = input().split()
k = int(k)
v, w, l = 0, 0, len(s)
for i in reversed(range(l)):
    if s[i] == '0':
        v += 1
    elif not v >= k:
        w += 1
if v >= k:
    print(w)
else:
    print(l-1)
