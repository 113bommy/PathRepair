import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N, Q = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]

    def segfunc(x, y):
        return max(x, y)

    def init(init_val):
        for i in range(n):
            seg[i + num - 1] = init_val[i]

        for i in range(num - 2, -1, -1):
            seg[i] = segfunc(seg[2 * i + 1], seg[2 * i + 2])

    def update(k, x):
        k += num - 1
        seg[k] = x
        while k:
            k = (k - 1) // 2
            seg[k] = segfunc(seg[k * 2 + 1], seg[k * 2 + 2])

    def query(p, q):
        if q <= p:
            return ide_ele
        p += num - 1
        q += num - 2
        res = ide_ele
        while q - p > 1:
            if p & 1 == 0:
                res = segfunc(res, seg[p])
            if q & 1 == 1:
                res = segfunc(res, seg[q])
                q -= 1
            p = p // 2
            q = (q - 1) // 2
        if p == q:
            res = segfunc(res, seg[p])
        else:
            res = segfunc(segfunc(res, seg[p]), seg[q])
        return res

    # seg tree初期値 (単位元)
    n = N
    ide_ele = 0
    num = 2 ** (n - 1).bit_length()
    seg = [ide_ele] * 2 * num

    init(A)

    def isOK(mid, m, value):
        a = query(m, mid)
        return a >= value


    B = A[::]

    for _ in range(Q):
        T, X, V = [int(x) for x in input().split()]
        if T == 1:
            update(X - 1, V)
            B[X - 1] = V
        elif T == 2:
            print(query(X - 1, V))
        else:
            a = query(X - 1, N)
            if a < V:
                print(N + 1)
            else:
                if B[X - 1] >= V:
                    print(X)
                    continue
                ok = N
                ng = X

                while abs(ok - ng) > 1:
                    mid = (ok + ng) // 2
                    if isOK(mid, X - 1, V):
                        ok = mid
                    else:
                        ng = mid

                print(ok)


if __name__ == '__main__':
    main()
