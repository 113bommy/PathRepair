imp = False
nodes = {}
for i in "abcdefghijklmnopqrstuvwxyz":
    nodes[i] = set()

n = int(input())
prev = None
for i in range(n):
    name = input()
    if prev:
        for x, y in zip(name, prev):
            if x != y:
                nodes[x].add(y)
                break
        else:
            if prev > name:
                imp = True
                break
    prev = name

q = []
r = []
for i in "abcdefghijklmnopqrstuvwxyz":
    if not nodes[i]:
        q.append(i)
    else:
        r.append(i)

l = []
while q:
    e = q.pop()
    l.append(e)
    for i in r[:]:
        if e in nodes[i]:
            nodes[i].remove(e)
            if not nodes[i]:
                q.append(i)
                r.remove(i)

if r or imp:
    print("Impossible")
else:
    print("".join(l))
