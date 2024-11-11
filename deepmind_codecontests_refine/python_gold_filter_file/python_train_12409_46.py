a, b = map(int, input().split())
c = 0
for i in range(a, b + 1):
    d = str(i)
    da = []
    fl = True
    for j in range(len(d)):
        if d[j] in da:
            fl = False
            break
        da.append(d[j])
    if fl:
        c = i
if c == 0:
    print(-1)
else:
    print(c)