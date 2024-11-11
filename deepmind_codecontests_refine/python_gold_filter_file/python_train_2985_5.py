def main():
    n = int(input())
    s = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    Max = 2 * sum(c)

    f = [x for x in c]
    # f[i] means when the last element in the 3-elements sequence is the i-th element in the original sequence
    # the minimum cost of the 3-element sequence
    for _ in range(2):
        for i in range(n - 1, -1, -1):
            min_fj = Max
            for j in range(i):
                if s[j] < s[i]:
                    min_fj = min(f[j], min_fj)
            if min_fj == Max:
                f[i] = Max
            else:
                f[i] = min_fj + c[i]

    min_cost = min(f)
    if min_cost == Max:
        print(-1)
    else:
        print(min_cost)


if __name__ == '__main__':
    main()
