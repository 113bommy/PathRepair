import os


def binary_search(f, low, high):
    mid = (high + low) // 2
    if low == high:
        return low

    if f(mid):
        return binary_search(f, mid + 1, high)
    else:
        return binary_search(f, low, mid)


# for i in range(10):
#     f = lambda x: x <= i
#     assert binary_search(f, 0, 100) == i + 1


def f(lr, k, s):
    d1s = 0
    d1c = 0
    d3s = 0
    d3c = 0

    n = len(lr)
    d2cs = [0]

    for l, r in lr:
        if r < k:
            d1s += l
            d1c += 1
        elif k < l:
            d3s += l
            d3c += 1
        else:
            d2cs.append(d2cs[-1] + l)

    if n // 2 < d1c:
        return False

    spend = d1s + d2cs[n // 2 - d1c] + max((n + 1) // 2 - d3c, 0) * k + d3s
    return spend <= s


def m(lr, s):
    if len(lr) == 1:
        return min(s, lr[0][1])

    lr = sorted(lr)
    k_low = lr[len(lr) // 2][0]
    return binary_search(lambda k: f(lr, k, s), k_low, max(r for l, r in lr) + 1) - 1


def pp(input):
    n_test = int(input())
    for i in range(n_test):
        n, s = map(int, input().split())
        lr = [tuple(map(int, input().split())) for _ in range(n)]
        print(m(lr, s))


if "paalto" in os.getcwd():
    from string_source import string_source

    s0 = string_source("""3
3 26
10 12
1 4
10 11
1 1337
1 1000000000
5 26
4 4
2 4
6 8
5 6
2 7""")

    pp(s0)

    s1 = string_source(
        """1
19 1175
44 87
68 100
93 98
76 79
10 58
74 99
87 97
23 75
62 73
100 100
71 76
73 87
76 82
44 84
54 90
2 82
67 99
85 97
66 88"""
    )
    pp(s1)
else:
    pp(input)
