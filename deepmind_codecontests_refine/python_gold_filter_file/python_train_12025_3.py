
n = int(input())
a, p = [], []
for i in range(n):
    x, z = map(int, input().split())
    a.append(x); p.append(z)
s = 0
i = 0
while i < n:
    tmp = 1
    s += p[i] * a[i]
    for j in range(i, n-1):
        if p[i] > p[j+1]:
            break
        s += p[i] * a[j+1]
        tmp += 1
    i += tmp
print(s)

# CodeForcesian
# ♥
# اگه میتونی تصور کنی پس حتما میتونی انجامش بدی
