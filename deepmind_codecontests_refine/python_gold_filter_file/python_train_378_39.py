n = int(input())
p = [int(x) for x in input().split(' ')]
p.sort()
e = 0
o = 0
for i in range(n // 2):
    e += abs(p[i] - (2 * i + 2))
    o += abs(p[i] - (2 * i + 1))
print(min(o, e))