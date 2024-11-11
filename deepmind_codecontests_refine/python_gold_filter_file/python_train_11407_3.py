n, x = map(int , input().split())
d = dict()
a = [int(x) for x in input().split()]
for i in a:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
k = 0
for i in a:
    c = d.get(i ^ x,  0)
    if i == i ^ x:
        k += (c - 1) / 2
    else:
        k += c / 2
print(int(k))