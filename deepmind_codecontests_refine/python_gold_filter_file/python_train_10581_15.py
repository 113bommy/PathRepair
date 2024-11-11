n, m = [int(i) for i in input().split()]
a, b = [int(i) for i in input().split()]
minimum = a/b
for i in range(n-1):
    a, b = [int(i) for i in input().split()]
    if a / b < minimum:
        minimum = a/b
print(minimum * m)