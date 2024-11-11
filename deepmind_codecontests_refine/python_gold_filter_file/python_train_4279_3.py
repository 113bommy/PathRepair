n, m, q = map(int, input().split())
x = [0 for i in range(n+1)]
b = input()
s = input()
for i in range(n-m+1):
    f = True
    for j in range(i, i+m):
        if b[j] != s[j-i]:
            f = False
            break
    if f:
        x[i+m] = 1
for i in range(1, n+1):
    x[i] = x[i] + x[i-1]
x += [x[-1] for i in range(m)]

for _ in range(q):
    l, r = map(int, input().split())
    print(max(x[r]-x[l+m-2], 0))