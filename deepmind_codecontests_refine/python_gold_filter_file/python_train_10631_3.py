n = int(input())
a = list(map(int, input().rstrip().split()))
print(n + 1)
print(1, n, 900000)
for i in range(n):
    print(2, i + 1, a[i] + 900000 - i)
