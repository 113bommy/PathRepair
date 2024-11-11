t = int(input())
for i10 in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    c = n // 2 + 1
    s = 0
    j = 1
    k1 = 0
    for i in range(n * k - 1, -1, -1):
        if k1 == k:
            break
        if j == c:
            k1 += 1
            j = 1
            s += a[i]
        else:
            j += 1
    print(s)
            