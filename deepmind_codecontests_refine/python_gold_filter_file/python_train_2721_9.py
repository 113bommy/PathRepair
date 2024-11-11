n = int(input())
l = list(map(int, input().split()))
q = 0
w = 0
e = 0
for i in range(n):
    if l[i] > 0:
        q += 1
    elif l[i] == 0:
        w += 1
    else:
        e += 1
if q >= w + e:
    print(1)
elif e >= w + q:
    print(-1)
else:
    print(0)