n = int(input())
a = list(map(int, input().split()))
a.sort()
min = 1000000000000000000
fin = 0
for i in range (1, n):
    if (min > abs(a[i - 1] - a[i])):
        min = abs(a[i - 1] - a[i])
        fin = 0
    if (min == abs(a[i - 1] - a[i])):
        fin += 1
print(min, fin)