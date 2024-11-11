def func(a, total):
    d = {}
    temp = total
    for no in a:
        if total - 1 >= 0:
            total -= 1
            if no in d:
                d[no] += 1
            else:
                d[no] = 1
        else:
            if no in d:
                del d[no]
            break
    if len(d) < 3:
        return 0,0,0
    gold = d[a[0]]
    del d[a[0]]
    if gold >= temp//2 +1:
        return 0,0,0
    silver = 0
    toDelete = []
    for key, val in d.items():
        silver += val
        toDelete.append(key)
        if silver > gold:
            break
    for key in toDelete:
        del d[key]
    if silver <= gold:
        return 0,0,0
    bronze = 0
    for key, val in d.items():
        bronze += val
    if bronze <= gold:
        return 0,0,0
    return gold, silver, bronze


for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    g,s,b = func(a, n//2)
    print("{} {} {}".format(g,s,b))
