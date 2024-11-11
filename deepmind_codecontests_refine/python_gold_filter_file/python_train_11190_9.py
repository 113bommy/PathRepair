w, m = map(int, input().split())
a = []
while m:
    a.append(m % w)
    m //= w
a.append(0)
for i, ai in enumerate(a):
    if ai <= 1:
        pass
    elif ai >= w - 1:
        a[i + 1] += 1
    else:
        print('NO')
        exit()
print('YES')