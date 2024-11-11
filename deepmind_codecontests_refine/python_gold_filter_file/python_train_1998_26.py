ar = []
for x in input().split(' '):
    ar.append(int(x))
n = ar[0]
k = ar[1]
ar2 = []
for x in input().split(' '):
    ar2.append(int(x))
curr = []
s = set()

for x in ar2:
    if x in s:
        continue
    if len(curr)==k:
        curr.append(x)
        s.add(x)
        s.discard(curr[0])
        curr.pop(0)
    else:
        curr.append(x)
        s.add(x)
print(len(curr))
print(*reversed(curr))
