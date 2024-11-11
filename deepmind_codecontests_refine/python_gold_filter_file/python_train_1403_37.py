n, k = [int(x) for x in input().split(' ')]
a = [int(x) for x in input().split(' ')]
a = [(x, i) for (i, x) in enumerate(a)]
a.sort(reverse=True)

r = []
while k > 0 and a:
    x = a.pop()
    if k >= x[0]:
        k -= x[0]
        r.append(x[1] + 1)

print(len(r))
if r:
    print(*r)