b, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
n = 0
for i in range(0, k - 1):
    n += a[i] * b
if a[k - 1] % 2 != 0:
    n += 1
if n % 2 == 0:
    print('even')
else:
    print('odd')
