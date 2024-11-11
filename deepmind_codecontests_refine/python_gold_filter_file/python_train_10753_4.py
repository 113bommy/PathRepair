t = int(input())

for _ in range(t):
    input()
    n, m = map(int, input().split())
    blocked = {}
    for _ in range(m):
        r, c = map(int, input().split())
        blocked[c] = blocked.get(c, [False, False])
        blocked[c][r - 1] = True
    bl = [(k, blocked[k]) for k in sorted(list(blocked.keys()))]
    st = -1
    pr = 0
    poss = True
    #print()
    for b, o in bl:
        bc = o.count(True)
        if st == -1 and bc == 2:
            pass
        elif st == -1:
            st = o.index(True)
            pr = b
            #print(b)
        else:
            #print(b, (b - pr + 1) % 2, o)
            if o[(b - pr + st) % 2]:
                poss = False
                break
            st = -1
    if st != -1:
        poss = False
    print("YES" if poss else "NO")
