input()
p = sorted(map(float, input().split(' ')))
m = max(p)
p = [(1 - i, i) for i in p]


def konv(a, b):
    return a[0] * b[0], a[0] * b[1] + a[1] * b[0]

while len(p) > 1:
    p.append(konv(p.pop(), p.pop()))
    m = max(m, p[-1][1])

print(m)