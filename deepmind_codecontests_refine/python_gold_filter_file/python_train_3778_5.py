import math
for test in range(int(input())):
    p, q = map(int, input().split())
    if p % q: 
        print(p)
        continue
    factors = [q]
    for f in range(2, int(math.sqrt(q)) + 1):
        if not q % f: 
            factors.append(f)
            factors.append(q // f)
    ans = 1
    for f in factors:
        tmp = p
        while not tmp % q and not tmp % f:
            tmp = tmp // f
        if tmp % q: ans = max(ans, tmp)
    print(ans)

