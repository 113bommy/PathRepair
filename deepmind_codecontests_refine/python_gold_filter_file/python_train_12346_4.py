import operator

fc = []
fd = []
n, c, d = map(int, input().split())

for _ in range(n):
    b, p, m = input().split()
    b, p = int(b), int(p)
    if m == 'C':
        if p <= c:
            fc.append((b, p))
    else:
        if p <= d:
            fd.append((b, p))

fc.sort(key=operator.itemgetter(0), reverse=True)
fd.sort(key=operator.itemgetter(0), reverse=True)

mx = 0
if fc and fd:
    mx = fc[0][0] + fd[0][0]

for i in range(len(fc)):
    b1, p1 = fc[i]
    if 2 * b1 <= mx:
        break
    for j in range(i + 1, len(fc)):
        b2, p2 = fc[j]
        if b1 + b2 <= mx:
            break
        if p1 + p2 <= c:
            mx = b1 + b2
            break
        
for i in range(len(fd)):
    b1, p1 = fd[i]
    if 2 * b1 <= mx:
        break
    for j in range(i + 1, len(fd)):
        b2, p2 = fd[j]
        if b1 + b2 <= mx:
            break
        if p1 + p2 <= d:
            mx = b1 + b2
            break

print(mx)

