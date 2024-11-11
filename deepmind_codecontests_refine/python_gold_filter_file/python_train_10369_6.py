

x, y, l, r = map(int, input().split())

all_reprs = set()

a = 0
while x ** a <= r:
    b = 0
    while x ** a + y ** b <= r:
        all_reprs.add(x ** a + y ** b)
        b += 1
    a += 1

sl = sorted(list(all_reprs))

result = 0

a = l

i = 0
while i < len(sl) and sl[i] < l: i += 1

prev = l - 1
while i < len(sl) and sl[i] <= r:
    result = max([result, sl[i] - prev - 1])
    prev = sl[i]
    i += 1

result = max([result, r - prev])

print(result)
