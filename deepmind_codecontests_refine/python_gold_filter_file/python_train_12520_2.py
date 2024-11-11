for t in range(int(input())):
    n = int(input())
    d = {}
    children = {}
    for i in range(n): d[i] = set()
    for i in range(n): children[i] = 0

    for i in range(n-1):
        u, v = map(int, input().split())
        d[u-1].add(v-1)
        d[v-1].add(u-1)

    child = []
    for i in d:
        if i != 0 and len(d[i]) == 1:
            child.append(i)

    p1 = []
    still = n-1

    while still != 0:
        still -= 1
        i = child.pop()
        p1.append(children[i])
        par = d[i].pop()
        children[par] += (1+children[i])
        d[par].remove(i)
        if len(d[par]) == 1 and par != 0: child.append(par)

    m1 = []
    for i in p1: m1.append((i+1)*(n-i-1))
    m1 = list(sorted(m1))[::-1]

    m = int(input())
    lm = list(map(int, input().split()))
    while len(lm) < n-1:
        lm.append(1)
    lm = list(sorted(lm))

    while len(lm) > n-1:
        new = (lm[-1]*lm[-2]) % (10**9+7)
        lm.pop()
        lm[-1] = new

    ans = 0
    for i in range(n-1):
        ans += lm[i]*m1[n-2-i]

    print(ans % (10**9+7))
