def main():
    n, k = map(int, input().split())
    ids = list(map(int, input().split()))

    res = 0
    for i in range(1, n + 1):
        ik = i * (i + 1) // 2
        if ik >= k:
            res = i - (ik - k)
            # print(i)
            res = ids[res - 1]
            break
    print(res)


if __name__ == '__main__':
    main()
