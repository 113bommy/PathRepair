N = int(input())
l = list(map(int, input().split()))
k1 = l[0]
L = l[1:]
l = list(map(int, input().split()))
k2 = l[0]
R = l[1:]

se = set([])
se.add(tuple(L))
se.add(tuple(R))
ans = 0
while True:
    # print(L, R)
    if len(L) == 0 or len(R) == 0:
        break
    top_L = L[0]
    top_R = R[0]
    L = L[1:]
    R = R[1:]
    if top_L > top_R:
        L = L + [top_R, top_L]
    else:
        R = R + [top_L, top_R]
    if tuple(L) in se and tuple(R) in se:
        print(-1)
        exit()
    se.add(tuple(L))
    se.add(tuple(R))
    ans += 1

if len(L) == 0:
    print("{} {}".format(ans, 2))
else:
    print("{} {}".format(ans, 1))
