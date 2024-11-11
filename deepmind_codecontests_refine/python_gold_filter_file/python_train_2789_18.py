N = int(input())
d = list(map(int, input().split()))

print((sum(d) ** 2 - sum(x ** 2 for x in d)) // 2)