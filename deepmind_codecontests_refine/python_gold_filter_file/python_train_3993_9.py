n, m, a = map(int, input().split())
req = (n // a) * (m // a)
flag1 = flag2 = False
if a >= m and a >= n:
    print(1)
    quit(0)
if n - (n // a) * a > 0:
    req += m // a
    flag1 = True
if m - (m // a) * a > 0:
    req += n // a
    flag2 = True
if flag1 and flag2:
    print(req + 1)
else:
    print(req)
