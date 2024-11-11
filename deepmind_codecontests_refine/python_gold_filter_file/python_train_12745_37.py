n, p, k = map(int, input().split())
if p >= 1 or p <= n:
    if p-k > 1:
        print('<<', end=" ")
    l = max(1, p-k)
    h = min(n, p+k)
    while l<=h:
        if l == p:
            print('('+str(p)+')', end=" ")
        else:
            print(l, end=" ")
        l += 1
    if p+k < n:
        print('>>', end=" ")