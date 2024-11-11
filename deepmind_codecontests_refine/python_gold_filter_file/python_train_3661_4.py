import sys
n, q = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
d = {}
d[0] = a[0]
b = []
b.append(0)
for i in range(1, n):
    d[i] = max(d[i-1], a[i])
    b.append(min(d[i-1], a[i]))
b[0] = d[n-1]

for _ in range(q):
    m = int(sys.stdin.readline())
    if m > n-1:
        first = d[n-1]
        m = (m-1) % (n-1)
        second = b[m+1]
    else:
        first = d[m-1]
        second = a[m]
    print(first, second)
