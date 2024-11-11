x = list(map(int, input().split()))
k, r = x[0], x[1]
for n in range (1, 11):
    if n * k % 10 == 0 or  n * k - r == 0 or (n * k) % 10 - r == 0:
        break
print(n)