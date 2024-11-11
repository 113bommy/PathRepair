#!/usr/bin/python3

def solve(N, A):
    if N == 1:
        return 0

    A.sort()

    fh = A[0:N]
    lh = A[N:]

    best = (max(fh) - min(fh)) * (max(lh) - min(lh))

    for i in range(1, N + 1):
        area = (A[-1] - A[0]) * (A[i + N - 1] - A[i])
        best = min(best, area)

    return best


def main():
    N = int(input())
    A = [int(e) for e in input().split(' ')]
    assert len(A) == 2 * N
    print(solve(N, A))


if __name__ == '__main__':
    main()
