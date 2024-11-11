import sys
import threading
from sys import stdin, stdout


sys.setrecursionlimit(10**9)
threading.stack_size(16*2048*2048)


def bandit_in_a_city(n, dic, a_a):
    r_a = dfs(1, -1, dic, a_a)
    return r_a[0]


def dfs(sq, fr, dic, a_a):

    w = a_a[sq-1]
    res = []
    if sq in dic:
        for nxt in dic[sq]:
            if nxt != fr:
                r = dfs(nxt, sq, dic, a_a)
                if res:
                    if res[0] < r[0]:
                        res[1] += (r[1] + (r[0] - res[0]) * res[2])
                        res[0] = r[0]
                    else:
                        res[1] += (r[1] + (res[0] - r[0]) * r[2])
                    res[2] += r[2]
                else:
                    res = r

    if res:
        if res[1] >= w:
            res[1] -= w
        else:
            a = w - res[1]
            b = (a // res[2])
            c = a % res[2]

            res[0] += b
            if c > 0:
                res[0] += 1
                res[1] = res[2] - c
            else:
                res[1] = 0
        return res
    else:
        return [w, 0, 1]


def solve():
    n = int(stdin.readline())
    p_a = list(map(int, stdin.readline().split()))
    a_a = list(map(int, stdin.readline().split()))

    dic = {}
    for i in range(len(p_a)):
        if p_a[i] not in dic:
            dic[p_a[i]] = []
        dic[p_a[i]].append(i+2)

    res = bandit_in_a_city(n, dic, a_a)
    stdout.write(str(res))


threading.Thread(target=solve).start()
