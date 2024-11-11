n = int(input())
w = []

for _ in range(n):
    s = input()
    if len(set(s)) <= 2:
        w.append(s)

d = set()
for s in w:
    d |= set(s)
d = list(d)

m = 0

for i in range(0, len(d)):
    for j in range(i, len(d)):
        total = 0
        s = set([d[i], d[j]])        
        for x in w:
            if set(x) <= s:
                total += len(x)
        m = max(m, total)

print(m)




