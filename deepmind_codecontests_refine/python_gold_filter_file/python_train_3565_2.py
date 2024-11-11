t = int(input())

for tt in range(t):
    n, k = map(int, input().split())
    s = input()

    ones = best = 0
    for i in range(k):
        cnt = 0
        for j in range(i, n, k):
            if s[j] == '1':
                cnt += 1
                ones += 1
            else:
                cnt = max(0, cnt - 1)

            best = max(cnt, best)


    print(ones - best)
