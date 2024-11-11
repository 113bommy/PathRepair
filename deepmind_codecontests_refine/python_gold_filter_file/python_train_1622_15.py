n = int(input())
a = [int(x) for x in input().split()]

res = []
s = a[0]
prev = 0
for i in range(1, len(a)):
    if s == 0:
        s += a[i]
    elif s + a[i] == 0:
        res.append((prev, i-1))
        s = a[i]
        prev = i
    else:
        s += a[i]

res.append((prev, n-1))

if s == 0:
    print("NO")
else:
    print("YES")
    print(len(res))
    for i, j in res:
        print(i+1, j+1)
