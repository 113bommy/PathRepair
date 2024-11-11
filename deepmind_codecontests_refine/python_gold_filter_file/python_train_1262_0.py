n = int(input())
r = []

i = 1
while i*i <= n:
    if n % i == 0:
        r.append(n * (i - 1) // 2 + i)
        if i*i != n:
            r.append(n * (n // i - 1) // 2 + n // i)
    i += 1
r.sort()

for i in range(0, len(r)):
    if i == 0 or (i > 0 and r[i] != r[i - 1]):
        print(int(r[i]), end=" ")
