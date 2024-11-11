N, A, B = map(int, input().split())


def f(n, a, b):
    if n == 1:
        return [a, b]

    mask = 1 << (n-1)
    if a & mask == b & mask:
        v1 = f(n-1, a, b)
        v2 = f(n-1, a ^ mask, v1[1] ^ mask)
        ret = v1[:1]
        ret.extend(v2)
        ret.extend(v1[1:])
        return ret
    else:
        v1 = f(n-1, a, a ^ 1)
        v2 = f(n-1, a ^ 1 ^ mask, b)
        v1.extend(v2)
        return v1


if bin(A ^ B).count('1') % 2 == 0:
    print("NO")
else:
    print("YES")
    res = f(N, A, B)
    for p in res:
        print(p)
