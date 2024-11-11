import math


def read():
    N, P = list(map(int, input().strip().split()))
    return N, P


def solve(N, P):
    # problem constraint
    if N >= 40:
        return 1
    # solve
    v3 = math.floor(P**(1/N)) + 1
    for v in range(v3, 0, -1):
        if P % (v**N) == 0:
            return v
    return 1


if __name__ == '__main__':
    inputs = read()
    print(solve(*inputs))
