n, m = map(int, input().split())
a = []
for i in range(n):
    a += [input()]
f = 0
face = 'face'
for i in range(n - 1):
    for j in range(m - 1):
        x = a[i][j:j + 2:] + a[i + 1][j:j + 2:]
        o = 1
        for k in range(4):
            if not(face[k] in x):
                o = 0
                break
        f += o
print (f)
