n, k = map(int, input().split())
a = [int(x) for x in input().split()]
b = a[:]
for i in range(1, n):
    a[i] += max(0, k-a[i]-a[i-1])
print(sum(a)-sum(b))
print(*a, sep=' ')
