l = list(map(int, input().split()))
a = l[0]
b = l[1]
x = []
for i in range(2, b + 1):
    for j in range(2, i):
        if (i % j == 0):
            break
    else:
        x.append(i)

f = list(set(x))
f.sort()
if f[-1] == b and f[-2] == a:
    print("YES")
else:
    print("NO")
