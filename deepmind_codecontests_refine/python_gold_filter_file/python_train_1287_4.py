n = int(input())
arr = list(map(int, input().split()))
x = sum(arr) % n
print(max([n - 1, x, n - x]))