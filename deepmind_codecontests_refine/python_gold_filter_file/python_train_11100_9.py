n, k = map(int, input().split())
L = list(map(int, input().split()))
d = {}
mx = L[0]
for i in range(1, n):
    mx = max(mx, L[i])
    if mx in d:
        d[mx] += 1
    else:
        d[mx] = 1
    if d[mx] == k:
        print(mx)
        exit()
print(mx)