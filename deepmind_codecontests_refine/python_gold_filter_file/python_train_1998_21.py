n, k = map(int, input().split())
a = [0] * k
l = 0
curr = set()

ids = map(int, input().split())

for id in ids:
    if id not in curr:
        curr.add(id)

        if a[-1] != 0:
            curr.remove(a[-1])

        a[1:] = a[:-1]
        a[0] = id
        l = min(l + 1, k)

print(l)
print(' '.join(map(str, a[:l])))
