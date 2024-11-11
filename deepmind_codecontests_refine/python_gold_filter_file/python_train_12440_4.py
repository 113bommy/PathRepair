n = int(input())
a = list(map(int, input().split()))
val = -1
for i in range(n):
    while a[i] % 2 == 0:
        a[i] //= 2
    while a[i] % 3 == 0:
        a[i] //= 3
    if val == -1:
        val = a[i]
    elif val != a[i]:
        print('No')
        exit(0)
print('Yes')