N, K, Q = map(int, input().split())
A = list(map(int, input().split()))
def list_split(arr, x):
    ret = []
    d = []
    for v in arr:
        if v >= x:
            d.append(v)
        elif d:
            ret.append(d)
            d = []
    else:
        if d:
            ret.append(d)
    return ret

ans = 10 ** 9
for x in sorted(A):
    y = []
    for arr in list_split(A, x):
        la = len(arr)
        if la >= K:
            y += sorted(arr)[:min(la - K + 1, Q)]
    if len(y) >= Q:
        ans = min(ans, sorted(y)[Q - 1] - x)

print(ans)