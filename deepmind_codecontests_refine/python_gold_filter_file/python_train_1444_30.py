n = int(input())
s = int(input())

if n == s:
    print(n + 1)
    exit()
elif n < s:
    print(-1)
    exit()

m = int(n ** 0.5) + 1

for b in range(2, m + 1):
    temp = n
    t = 0
    while temp >= b:
        t += temp % b
        temp //= b
    if s == t + temp:
        print(b)
        exit()

for p in range(m, 0, -1):
    if (n - s) % p != 0:
        continue
    b = (n - s) // p + 1
    temp = n
    t = 0
    while temp >= b:
        t += temp % b
        temp //= b
    if s == t + temp:
        print(b)
        exit()

print(-1)
