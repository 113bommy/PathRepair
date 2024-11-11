n, q = int(input()), [9]
t = [int(c) for c in input()]
for i in range(n):
    p = [(s - t[0]) % 10 for s in t]
    if p < q: q = p
    t.append(t.pop(0))
print(''.join(map(str, q)))