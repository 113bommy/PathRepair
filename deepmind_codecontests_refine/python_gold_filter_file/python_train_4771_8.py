n = int(input())
A = []

for s in range(n + 1):
    count = 0
    t = n - s
    while s > 0:
        count += s % 6
        s //= 6
    while t > 0:
        count += t % 9
        t //= 9
    A.append(count)
    
print(min(A))