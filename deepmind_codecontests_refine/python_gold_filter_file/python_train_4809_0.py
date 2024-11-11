for __ in range(int(input())):
    n = int(input())
    ar1 = list(map(int, input().split()))
    ar = ar1.copy()
    lol = set()
    for j in range(1, n + 1):
        lol.add(j)
    lol.discard(ar[0])
    for i in range(1, n):
        if ar1[i] > ar1[i - 1]:
            lol.discard(ar1[i])
        else:
            ar[i] = 0
    kek = list(lol)
    kek.sort()
    num = 0
    flag = 0
    for j in range(n):
        if ar[j] == 0:
            ar[j] = kek[num]
            num += 1
        if ar[j] > ar1[j]:
            flag = 1
    if flag == 1:
        print(-1)
    else:
        print(*ar)
