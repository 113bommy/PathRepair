n, a, b = map(int, input().split())
l = [*map(int, input().split())]
s = l[0]
del l[0]
x = ((s * a) // b) - s
l.sort()
net = res = 0
for e in l:
    if net + e > x: break
    net += e
    res += 1
print(n - 1 - res)