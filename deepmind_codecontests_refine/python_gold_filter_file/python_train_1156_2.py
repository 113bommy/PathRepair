n = int(input())
if n == 1:
    print(1, 0)
    exit()
cnts = []
i = 2
result = 1
while i * i <= n:
    if n % i == 0:
        result *= i
        c = 0
        while n % i == 0:
            c += 1
            n //= i
        cnts.append(c)
    i += 1
if n > 1:
    cnts.append(1)
    result *= n
m = 0
if not (cnts.count(cnts[0]) == len(cnts) and cnts[0] & (cnts[0] - 1) == 0):
    m += 1
    d = max(cnts)
    r = 1
    while r < d:
        r <<= 1
        m += 1
else:
    d = max(cnts)
    while d != 1:
        m += 1
        d >>= 1
print(result, m)
        
