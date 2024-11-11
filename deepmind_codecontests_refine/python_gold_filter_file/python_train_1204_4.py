def genprimes(limit):
    lim12 = max(limit, 12)
    lim = lim12 // 6
    sieve = [False, True, True] * lim
    lim = lim * 3 - 1
    for i, s in enumerate(sieve):
        if s:
            p, pp = i * 2 + 3, (i + 3) * i * 2 + 3
            le = (lim - pp) // p + 1
            if le > 0:
                sieve[pp::p] = [False] * le
            else:
                break
    sieve[0] = sieve[3] = True
    res = [i for i, s in zip(range(3, lim12, 2), sieve) if s]
    res[:4] = (2, 3, 5, 7)
    while res[-1] >= limit:
        del res[-1]
    return res


def main():
    n = int(input())
    ss = list(map(int, input().split()))
    mx = max(ss) + 1
    l = [0] * mx
    for s in ss:
        l[s] += 1
    res = [1]
    for p in genprimes(mx+1):
        res.append(sum(l[::p]))
    print(max(res))


if __name__ == '__main__':
    main()
