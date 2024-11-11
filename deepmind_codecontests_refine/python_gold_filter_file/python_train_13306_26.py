l = int(input())
l -= 1
to = [[] for _ in range(14)]
for i in range(1, 13):
    to[i].append((i + 1, 0 * 3 ** (12 - i)))
    to[i].append((i + 1, 1 * 3 ** (12 - i)))
    to[i].append((i + 1, 2 * 3 ** (12 - i)))
d = []
l_upto = []
t = l
s = 0
for i in range(13):
    d.append(t % 3)
    s += (t % 3) * 3 ** i
    l_upto.append(s)
    t //= 3

for i, t in enumerate(d):
    for s in range(t + (i == 0)):
        to[0].append((13 - i, l - l_upto[i] + 3 ** i * s))
print(14, sum(map(len, to)))
for i in range(len(to)):
    for j, cost in to[i]:
        print(i + 1, j + 1, cost)

