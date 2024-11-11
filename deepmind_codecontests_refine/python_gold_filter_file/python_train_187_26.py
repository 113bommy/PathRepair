n = int(input())
f = []
for _ in range(n):
    s = 0
    l = list(map(int, input().split()))
    for i in range(10):
        s += l[i]<<i
    f.append(s)
p = [list(map(int, input().split())) for _ in range(n)]
b = []
for i in range(1,1024):
    w = 0
    for j in range(n):
        idx = format(i & f[j], 'b').count('1')
        w += p[j][idx]
    b.append(w)
print(max(b))