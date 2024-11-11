n, z = map(int, input().split())
arrs = [int(x) for x in input().split()]
arrs.sort()

def fi(k):
    l = arrs[:k]
    r = arrs[-k:]
    return all([r[i] - l[i] >= z for i in range(len(r))])

l = 0; r = len(arrs) // 2 + 1
while r - l > 1:
    m = (l + r) // 2
    if fi(m):
        l = m
    else:
        r = m
print(l)

