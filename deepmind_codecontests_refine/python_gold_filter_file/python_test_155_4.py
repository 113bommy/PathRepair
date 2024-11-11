for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(" ")))
    s = input()

    cnt = s.count('0')
    lmemo = [0 for _ in range(cnt)]
    umemo = [0 for _ in range(n - cnt)]
    for i in range(n):
        if s[i] == '0' and a[i] <= cnt:
            lmemo[a[i] - 1] = 1
        if s[i] == '1' and a[i] > cnt:
            umemo[a[i] - cnt - 1] = 1


    lcnt = 0
    ucnt = 0
    for i in range(n):
        if s[i] == '0' and a[i] > cnt:
            while True:
                if lmemo[lcnt] == 1:
                    lcnt += 1
                else:
                    break
            a[i] = lcnt + 1
            lcnt += 1
        if s[i] == '1' and a[i] <= cnt:
            while True:
                if umemo[ucnt] == 1:
                    ucnt += 1
                else:
                    break
            a[i] = ucnt + 1 + cnt
            ucnt += 1

    print(" ".join(map(str, a)))
