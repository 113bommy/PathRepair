from bisect import bisect


def main():
    n = int(input())
    an = [(i, int(s)) for i, s in enumerate(input().split())][:n]

    ans = sum(a * (-n + 1 + 2 * i) for i, a in an)

    group = {}
    for i, a in an:
        if a not in group:
            group[a] = []
        group[a].append(i)
    group = list(sorted(group.items(), key=lambda t: t[0]))
    # print(group)

    for i in range(len(group) - 1):
        if group[i][0] + 1 == group[i + 1][0]:
            idx_s1 = group[i][1]
            idx_s2 = group[i + 1][1]
            for idx in idx_s1:
                smaller = bisect(idx_s2, idx)
                larger = len(idx_s2) - smaller
                ans = ans - larger + smaller

    print(ans)


if __name__ == '__main__':
    main()
