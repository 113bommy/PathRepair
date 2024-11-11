input()
a = list(map(int, input().split()))
a.sort(reverse=True)
i, c = 0, 0
m = list()
while i < len(a)-1:
    if a[i] == a[i+1]:
        m.append(a[i])
        i += 1
        c += 1
    i += 1
    if c == 2:
        break
if c == 2:
    print(m[0]*m[1])
else:
    print(0)