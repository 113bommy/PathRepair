def main():
    n, k = map(int, input().split())
    l = list(map(int, input().split()))
    diff, res = 10000, []
    while True:
        i = min(range(n), key=l.__getitem__)
        j = max(range(n), key=l.__getitem__)
        if diff > l[j] - l[i]:
            diff = l[j] - l[i]
            top = len(res)
            if diff < 2:
                break
        if len(res) == k:
            break
        l[i] += 1
        l[j] -= 1
        res.append(' '.join((str(j + 1), str(i + 1))))
    print(max(l) - min(l), top)
    if top:
        print('\n'.join(res[:top]))


if __name__ == '__main__':
    main()