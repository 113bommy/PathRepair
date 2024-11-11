ins = map(int, input().split())
b1, q, limit, n = next(ins), next(ins), next(ins), next(ins)

bads_map = {}
bads = map(int, input().split())

for bad in bads:
    bads_map[bad] = bads_map.get(bad, True)

if abs(b1) > limit:
    print(0)
elif b1 == 0:
    if 0 in bads_map:
        print(0)
    else:
        print("inf")
elif q == 1:
    if b1 in bads_map:
        print(0)
    else:
        print("inf")
elif q == -1:
    if b1 in bads_map and (-b1) in bads_map:
        print(0)
    else:
        print("inf")
elif q == 0:
    if 0 not in bads_map:
        print("inf")
    elif b1 in bads_map:
        print(0)
    else:
        print(1)
else:
    ans = 0
    while abs(b1) <= limit:
        if b1 not in bads_map:
            ans += 1
        b1 *= q
    print(ans)