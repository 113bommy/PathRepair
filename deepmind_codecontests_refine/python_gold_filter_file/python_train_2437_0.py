n = int(input())
a = list(map(int, input().split()))
b = []
a = sorted(a)
b = [a[-1]] + a[1:(n-1)] + [a[0]]
print(*b)
