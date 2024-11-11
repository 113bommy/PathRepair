n, m = [int(i) for i in input().split()]
for i in range(m):
    if n % 10 == 0:
        n /= 10
    else:
        n-= 1
print(int(n))