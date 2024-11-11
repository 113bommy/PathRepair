for _ in range(int(input())):
    n, m = map(int, input().split())
    li = list(map(int, input().split()))
    li1 = sorted(li)
    p = list(map(int, input().split()))
    k = 1
    while k <= 100:
        for i in p:
            for j in range(100):
                try:
                    if li[i-1] > li[i]:
                        li[i-1], li[i] = li[i], li[i-1]
                    else:
                        break
                except:
                    break
        k += 1
    if li == li1:
        print('YES')
    else:
        print('NO')
