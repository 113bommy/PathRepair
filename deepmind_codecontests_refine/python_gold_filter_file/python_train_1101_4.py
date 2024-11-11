b, q, l, m = list(map(int, input().split()))
a = set(list(map(int, input().split())))
ans = 0
boo = False
i = 0
while (i < 34) and (abs(b) <= l):
    if (b not in a):
        ans += 1
        if i > 31:
            boo = True
    b *= q
    i += 1
if boo:
    print('inf')
else:
    print(ans)