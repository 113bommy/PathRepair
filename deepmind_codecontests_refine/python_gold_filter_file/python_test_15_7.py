import sys


def input():
    return sys.stdin.readline().strip('\n')


def cin_int_ls():
    return list(map(int, input().split()))


def cin_int():
    return int(input())


from collections import Counter


def sv(data, k):
    left = Counter()
    right = Counter()
    top = {}
    all_start = set()
    for i in range(len(data)):
        for j in range(len(data[0])):
            if data[i][j] == '*':
                all_start.add((i, j))
                left[(i, j)] = left[(i - 1, j - 1)] + 1
                right[(i, j)] = right[(i - 1, j + 1)] + 1
                l, r = left[(i, j)], right[(i, j)]
                if l - 1 >= k and r - 1 >= k:
                    top[(i, j)] = min(l, r)
    for p, d in top.items():
        x, y = p
        rm = set()
        for i in range(d):
            rm.add((x - i, y - i))
            rm.add((x - i, y + i))
        all_start -= rm
    if all_start:
        return 'NO'
    else:
        return 'YES'


for _ in range(cin_int()):
    n, m, k = cin_int_ls()
    data = []
    for _ in range(n):
        data.append(input())
    print(sv(data, k))
