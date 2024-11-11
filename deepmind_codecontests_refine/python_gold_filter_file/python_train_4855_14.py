x = int(input())


def pow2(k):
    d = 1
    for z in range(k):
        d = d * 2
    return d


L = list()
L.append(1)
i = 3
j = 1
while j < 17:
    res = pow2(2 * j + 1) - pow2(j)
    L.append(res)
    j = j + 1

s = 0
r = 1
while L[s] <= x:
    if x % L[s] == 0:
        r = L[s]
    s = s + 1
print(r)
