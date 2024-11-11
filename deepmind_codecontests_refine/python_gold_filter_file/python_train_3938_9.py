def main():
    S = list(input())

    N = len(S)

    if (S[0] == '0') or (S[-1] == '1'):
        print (-1)
        return 0

    lst = []
    for i in range((N - 1) // 2):
        if S[i] != S[N - 2 - i]:
            print (-1)
            return 0
        if S[i] == '1':
            lst.append(i + 1)
    if N % 2 == 0 and S[N//2 - 1] == '1':
        lst.append(N//2)
    # print (lst)

    if lst[-1] * 2 != N:
        center = lst[-1] + 1
        for x in range(lst[-1] * 2 + 2, N + 1):
            print (center, x)

        before = 1
        n = lst[-1] * 2 + 2
        tmp = 1
        for tmp in lst[1:]:
            print (before, tmp)
            print (n - before, n - tmp)
            for x in range(tmp - before - 1):
                print (before + 1 + x, tmp)
                print (n - (before + 1 + x), n - tmp)
            before = tmp
        print (tmp, center)
        print (n - tmp, center)

    if lst[-1] * 2 == N:
        before = 1
        n = lst[-1] * 2 + 1
        tmp = 1
        for tmp in lst[1:]:
            print (before, tmp)
            print (n - before, n - tmp)
            for x in range(tmp - before - 1):
                print (before + 1 + x, tmp)
                print (n - (before + 1 + x), n - tmp)
            before = tmp
        print (tmp, n - tmp)

if __name__ == '__main__':
    main()