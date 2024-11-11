n = int(input())
arr = [int(x) for x in input().split(' ')]
a, b = [min(arr.index(1), arr.index(n)), max(arr.index(1), arr.index(n))]
print(b - a + max(a, n - b - 1))