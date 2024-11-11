n = int(input())
a = list(map(int, input().split()))
suma = sum(a)
print(max(n - 1, n - suma % n))
