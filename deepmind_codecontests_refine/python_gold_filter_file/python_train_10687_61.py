n, k = [int(x) for x in input().split()]

for _ in range(0, k):
    if n % 10 == 0:
        n /= 10
    else:
        n -= 1
print(int(n))