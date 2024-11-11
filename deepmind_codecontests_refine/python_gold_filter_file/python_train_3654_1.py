import sys

read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
t = int(input())
for case in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    tmp = 10 ** 4  # INF
    ans = 10 ** 9
    i = 0
    rec = (0, 0)
    break_bit = 0
    while i < n - 1:
        # ペアを探す
        cnt = 2
        if a[i] == a[i + 1]:
            if ans > a[i] / tmp + tmp / a[i]:
                rec = (tmp, a[i])
                ans = a[i] / tmp + tmp / a[i]
            while i + 2 < n and a[i + 1] == a[i + 2]:
                cnt += 1
                i += 1
                # print(i, cnt)
                if cnt == 4:
                    rec = (a[i], a[i])
                    # print(rec)
                    break_bit = 1
                    break

            tmp = a[i]
        if break_bit == 1:
            break
        i += 1
    print(rec[0], rec[0], rec[1], rec[1])
