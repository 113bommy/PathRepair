import operator
from functools import reduce
N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

positives = [a for a in A if a > 0]
negatives = [a for a in A if a < 0]
positive_cnt = len(positives)
negative_cnt = len(negatives)
zero_cnt = A.count(0)


if 2 * min(K // 2, negative_cnt // 2) + positive_cnt >= K:
    ans = 1
    positives.sort(key=lambda x: abs(x), reverse=True)
    negatives.sort(key=lambda x: abs(x), reverse=True)

    if K % 2 == 1:
        ans *= positives.pop(0)
        K -= 1

    X = []
    for pair in zip(*[iter(positives)] * 2):
        X.append(reduce(operator.mul, pair, 1))
    for pair in zip(*[iter(negatives)] * 2):
        X.append(reduce(operator.mul, pair, 1))
    X.sort(reverse=True)

    ans *= reduce(lambda a, b: a * b % MOD, X[:K // 2], 1)
    print(ans % MOD)

elif zero_cnt:
    print(0)

else:
    A.sort(key=lambda x: abs(x))
    print(reduce(lambda a, b: a * b % MOD, A[:K], 1) % MOD)
