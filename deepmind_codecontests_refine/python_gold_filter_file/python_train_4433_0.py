input()
a = input()
b, c = "ACGT?", [0] * 5
for i in a:
    c[b.index(i)] += 1
for i in range(c.pop()):
    a = a.replace("?", b[c.index(min(c))], 1)
    c [c.index(min(c))] += 1
print([a, "==="][len(set(c)) != 1])
