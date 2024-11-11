q = int(input())
for z in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    d = {}
    _m  = 1000000000000000
    if len(a) == 1:
        print(-1)
        continue
    for j, i in enumerate(a):
        if i not in d:
            d[i] = [j]
        else:
            d[i].append(j)
    o= False
    for k, v in d.items():
        if len(v) > 1:
            o = True
            j = len(v) - 2
            _min = 12123123132132
            while j >= 0:
                if abs(v[j + 1] - v[j] ) + 1 < _min:
                    _min = abs(v[j] - v[j + 1]) + 1
                j -= 1
            _m = min(_m, _min)
    if not o:
        print(-1)
    else:
        print(_m)
        