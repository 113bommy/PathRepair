n = eval(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])
a = sorted(a)
if n % 2 == 1:
    print(a[n // 2])
else:
    print(a[n // 2 - 1])