input()
x = ['a']
d = []
for c in input():
    i = 0
    while c < x[i]:
        i += 1
        if i == len(x): x.append(c)
    x[i] = c
    d.append(i + 1)
print(max(d), *d)