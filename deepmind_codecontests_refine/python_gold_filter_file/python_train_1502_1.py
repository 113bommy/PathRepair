from collections import Counter


def solve(s, n, p, money):
    def get_price(count):
        return sum(max(r[i] * count - n[i], 0) * p[i] for i in range(3))

    c = Counter(s)
    r = [c['B'], c['S'], c['C']]

    x = (money + n[0] * p[0] + n[1] * p[1] + n[2] * p[2]) // (r[0] * p[0] + r[1] * p[1] + r[2] * p[2])
    li, ro = 0, 10 ** 12 + 100
    feasible_count = 0
    while li <= ro:
        mi = (li + ro) // 2
        if get_price(mi) > money:
            ro = mi - 1
        else:
            feasible_count = mi
            li = mi + 1

    return feasible_count


# assert solve('BBBSSC', [6, 4, 1], [1, 2, 3], 4) == 2
s = input()
n = list(map(int, input().split()))
p = list(map(int, input().split()))
r = int(input())
print(solve(s, n, p, r))
