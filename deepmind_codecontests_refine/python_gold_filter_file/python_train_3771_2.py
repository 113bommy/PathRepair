def r(t=int):
    return list(map(t, input().split()))


def ri(t=int):
    return t(input())


def cd(it):
    ret_val = dict()
    for v in it:
        ret_val[v] = ret_val.get(v, 0) + 1
    return ret_val


n = ri()

ans = [0] * n
alphabet = 'abcdefghijklmnopqrstuvwxyz'
a = [alphabet.index(ai) for ai in input()]
pa = []

for i, ai in enumerate(a):
    m = 100
    for h, p in enumerate(pa):
        p1 = ai - p
        if p <= ai and p1 < m:
            f = h + 1
            m = p1

    if m == 100:
        pa.append(ai)
        f = len(pa)

    ans[i] = f
    pa[f-1] = ai

print(len(pa))
print(' '.join(str(i) for i in ans))

'''
9
abacbecfd
'''