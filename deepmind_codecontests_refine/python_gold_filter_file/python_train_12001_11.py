testcase = int(input())
while testcase:
    n,k = map(int, input().split())
    N = sorted(list(map(int, input().split())))
    a = N[0]
    count = 0
    for ind in range(1, len(N)):
        if N[ind]>k:
            continue
        count += int((k-N[ind])/a)

    print(count)
    testcase -= 1