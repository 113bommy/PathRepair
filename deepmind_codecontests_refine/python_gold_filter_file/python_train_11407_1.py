n,x = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
cs = {}
for v in a:
    cs[v] = cs.get(v, 0) + 1
t = 0
for v in a:
    t += cs.get(x ^ v, 0)

if x == 0:
    t -= n
print(t // 2)