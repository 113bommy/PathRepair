from math import ceil, floor
Q = int(input())
for _ in range(Q):
    a, b, m = map(int, input().split())
    if b - a == 0:
        print(1, a)
        continue
    if b - a <= m:
        print(2, a, b)
        continue
    x = max(0, ceil(b/(a+m)) - 1)
    y = max(0, floor(b/(a+1)))
    if x.bit_length() < y.bit_length():
        h = y.bit_length()
        t = b - a*2**(h-1)
        M = [t//(2**(h-1))]*h
        t %= 2**(h-1)
        for i in range(h-1):
            j = h - 2 - i
            if 2**j & t:
                M[i] += 1
        sumi = a
        ans = [a] + [0]*h
        assert all(m > 0 for m in M), ''
        for i in range(1, h+1):
            ans[i] = sumi + M[i-1]
            sumi += ans[i]
        if len(ans) > 50:
            print(-1)
        else:
            print(len(ans), *ans)
    else:
        print(-1)