from sys import stdin, stdout

input = stdin.readline
rstr = lambda: input().strip()
rstrs = lambda: [str(x) for x in input().split()]
rstr_2d = lambda n: [rstr() for _ in range(n)]
rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]
rint_2d = lambda n: [rint() for _ in range(n)]
rints_2d = lambda n: [rints() for _ in range(n)]

n, s = rints()
a = rints()
if sum(a) < s:
    print(-1)
else:
    mi, diff = min(a), 0
    for i in a:
        diff += i - mi

    s -= diff
    if s <= 0:
        print(mi)
    else:
        print((mi * n - s) // n)
