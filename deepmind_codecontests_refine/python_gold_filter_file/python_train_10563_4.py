n, m = map(int, input().split())
d = dict()
for i in range(m):
    a, b = input().split()
    d[a] = a if len(a) <= len(b) else b

arr = list(input().split())
for i in arr:
    print(d[i], end=' ')
