import collections


def main(N, D):
    Dcounter = collections.Counter(D)
    a = [0, 24]
    b = []
    for i, v in Dcounter.items():
        if v > 2 or (i == 0 and v > 0) or (i == 12 and v > 1):
            print(0)
            return

        if v == 2:
            a.append(i)
            a.append(24-i)
        if v == 1:
            b.append(i)
    ans = 0
    for i in range(1 << len(b)):
        use = a.copy()
        for j in range(len(b)):
            if ((i >> j) & 1) == 1:
                use.append(b[j])
            else:
                use.append(24-b[j])
        use = sorted(use)
        distance = [use[i+1] - use[i] for i in range(len(use)-1)]
        ans = max(ans, min(distance))
    print(ans)

if __name__ == "__main__":
    N = int(input())
    D = list(map(int, input().split(" ")))
    main(N, D)
