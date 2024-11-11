import sys

input = sys.stdin.readline


def main():
    K, Q = map(int, input().split())
    D = list(map(int, input().split()))

    for _ in range(Q):
        n, x, m = map(int, input().split())
        md = [D[i] % m for i in range(K)]
        smda = 0
        mda0 = 0
        for i in range((n - 1) % K):
            if md[i] == 0:
                mda0 += 1
            smda += md[i]
        smd = smda
        md0 = mda0
        for i in range((n - 1) % K, K):
            if md[i] == 0:
                md0 += 1
            smd += md[i]
        roop = (n - 1) // K
        res = n - 1 - (x % m + smd * roop + smda) // m - md0 * roop - mda0
        print(res)


main()
