n = int(input())
num = n
d = {}

while n % 2 == 0:
    d[2] = 2 if 2 not in d else d[2] * 2

    n //= 2
#print(n, int(math.sqrt(n)) + 1)
i = 3; ans = float('inf')

while i * i <= n:

    while n % i == 0:
        d[i] = i if i not in d else d[i] * i

        n //= i

    i += 2
    
if n > 2:
    d[n] = n
pf = list(d.items())

for i in range(1, 1 << len(pf)):
    p = 1
    for j in range(len(pf)):
        if i & (1 << j) > 0:
            p *= pf[j][1]
    #print(p)
    ans = min(ans, max(p, num // p))
if num == 1:
    print(1, 1)
else:
    print(num // ans, ans)
