import sys
from itertools import accumulate


def solve(n, x, m):
    eee = [d % m for d in ddd]
    acc = list(accumulate(eee))
    zero = [int(e == 0) for e in eee]
    zero_acc = list(accumulate(zero))
    loop, rem = divmod(n - 1, k)
    tot = x % m + acc[-1] * loop
    tot_zero = zero_acc[-1] * loop
    if rem > 0:
        tot += acc[rem - 1]
        tot_zero += zero_acc[rem - 1]
    dame = tot // m
    # print(n, x, m)
    # print(eee)
    # print(acc)
    # print(loop, rem)
    # print(tot, dame)
    return n - 1 - dame - tot_zero


k, q = map(int, input().split())
ddd = list(map(int, input().split()))
buf = []
for line in sys.stdin:
    n, x, m = map(int, line.split())
    buf.append(solve(n, x, m))
print('\n'.join(map(str, buf)))
