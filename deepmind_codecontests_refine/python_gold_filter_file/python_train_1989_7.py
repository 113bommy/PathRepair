n = int(input())
m = int(input())
a = [int(input()) for i in range(n)]
a1 = max((sum(a) + m - 1) // n + 1, max(a))
print(a1, m + max(a))