a = int(input())
b = list(input())
for i in range(a):
    b[i] = int(b[i])
har = []
for i in range(a):
    c, d = map(int,input().split())
    har.append((c, d))
ma = sum(b)
for i in range(10000):
    for j in range(a):
        if i >= har[j][1] and (i - har[j][1]) % har[j][0] == 0:
            b[j] = 1 - b[j]
    ma = max(ma, sum(b))
print(ma)
