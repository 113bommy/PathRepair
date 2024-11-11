T = int(input())
lis = []
for i in range(100):
    lis.append(2**i-1)
for kase in range(T):
    l, r = [int(x) for x in input().split()]
    x, y = l, r
    if l==r:
        print(l)
        continue
    i = 100
    while True:
        if (l&2**i)==(r&2**i):
            if (l&2**i):
                l-=2**i
                r-=2**i
        else:
            break
        i -= 1
    if r in lis:
        print(r|y)
    else:
        print((y-2**i)|(2**i-1))