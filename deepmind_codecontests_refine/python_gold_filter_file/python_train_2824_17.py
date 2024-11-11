n, k = map(int, input().split())
c = list(map(int, input().split()))
m = 1
z = 0
e = 0
while e < n:
    while e + 1 < n and c[e] != c[e + 1]:
        e += 1
    m = max(m, e - z + 1)
    while e + 1 < n and c[e] == c[e + 1]:
        e += 1
    z = e
    e += 1
print(m)
