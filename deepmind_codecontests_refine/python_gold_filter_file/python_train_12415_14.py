from sys import stdin, gettrace, stderr

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def solve():
    n = int(inputi())
    aa = [int(a) for a in inputi().split()]
    counts = [0]*(n+1)
    for a in aa:
        counts[a] += 1
    res = []
    loop(aa, counts, n, res)

    print(len(res))
    # print(aa, file=stderr)
    print(' '.join(map(str, res )))


def loop(aa, counts, n, res):
    while True:
        mex = counts.index(0)
        if mex == n:
            i = 0
            for i in range(n):
                if aa[i] < i:
                    break
            else:
                return
            counts[aa[i]] -= 1
            aa[i] = mex
            counts[n] = 1
            res.append(i+1)
        else:
            counts[mex] += 1
            counts[aa[mex]] -= 1
            aa[mex] = mex
            res.append(mex+1)


def main():
    t = int(inputi())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()