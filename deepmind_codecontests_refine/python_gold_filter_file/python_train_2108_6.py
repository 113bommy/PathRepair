t = int(input())

for _ in range(t):
    n = int(input())

    m = 1
    cnt = 1
    ans = []

    power = 2
    while m != n:
        if n - m < 2 * power:
            if n - m <= power:
                ans.append(n - m - cnt)
                m = n
            else:
                add = (n - m) // 2
                ans.append(add - cnt)
                cnt += add - cnt
                m += cnt
                bl = add != n - m
                ans.append(int(bl))
                cnt += bl
                m += cnt

        else:
            ans.append(cnt)
            cnt *= 2
            m += cnt

        power *= 2

    print(len(ans))
    print(*ans)
