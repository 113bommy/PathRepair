n = int(input())
a = list(map(int, input().split(" ")))
a.sort()
result = 0
for i in range(1, n):
    while a[i] <= a[i-1]:
        a[i] += 1
        result += 1
print(result)
