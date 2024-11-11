n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
zero = False
for i in range(n):
    if k:
        if a[i] < 0:
            k -= 1
            a[i] *= -1
    if a[i] == 0:
        zero = True

if zero:
    print(sum(a))
else:
    if k & 1:
        print(sum(a) - 2 * min(a))
    else:
        print(sum(a))