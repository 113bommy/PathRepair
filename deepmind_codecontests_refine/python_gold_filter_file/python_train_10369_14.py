x, y, l, r = map(int, input().split())
a = set()
i = 0
j = 0
while x**i <= r:
    j = 0
    while x**i + y ** j <= r:
        if (x**i + y**j >= l) and (x**i + y**j <= r):
            a.add(x**i + y**j)
        j += 1
    i += 1
a = list(a)
a.sort()
ma = 0
length = len(a)
for i in range(1, length):
    if a[i] - a[i - 1] - 1 > ma:
        ma = a[i] - a[i - 1] - 1
if len(a) > 0:
    if a[0] - l > ma:
        ma = a[0] - l
    if r - a[length - 1] > ma:
        ma = r - a[length - 1]
    print(ma)
else:
    print(r - l + 1)