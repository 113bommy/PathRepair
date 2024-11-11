if __name__ == '__main__':
    n = int(input())
    arrs = list(map(int, input().split()))
    if n == 1:
        print(1)
        exit(0)
    half = sum(arrs) / 2
    added = 0
    i = 0
    while added < half:
        added += arrs[i]
        i += 1
    print(i)
