x = int(input())
m = list(map(int, input().split()))
a, b, c = [], [], []
for i in range(x):
    if m[i] == 1:
        a.append(i+1)
    elif m[i] == 2:
        b.append(i+1)
    else:
        c.append(i+1)
t = (min(len(a), len(b), len(c)))
print(t)
for i in range(t):
    print(a[i], b[i], c[i])