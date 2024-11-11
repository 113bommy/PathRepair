def bitcount(N):  # 立ってるbitの数
    bitcnt = [0]
    for _ in range(N):
        bitcnt += [i + 1 for i in bitcnt]
    return bitcnt


n, x = int(input()), input()

num, cnt = int(x, 2), x.count('1')
lbit = bitcount(18)
for i in range(n):
    ans = 1
    if x[i] == '0':
        ctmp = cnt + 1
        tmp = num % ctmp + pow(2, n - (i + 1), ctmp)
    elif x[i] == '1':
        if cnt == 1:
            print(0)
            continue
        ctmp = cnt - 1
        tmp = num % ctmp - pow(2, n - (i + 1), ctmp)
    tmp %= ctmp
    ctmp = lbit[tmp]
    while tmp > 0:
        ans += 1
        tmp %= ctmp
        ctmp = lbit[tmp]
    print(ans)
