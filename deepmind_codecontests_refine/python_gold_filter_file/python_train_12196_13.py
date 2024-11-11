n = int(input())
d = []
for i in range(4):
    d.append(n % 2)
    n //= 2
x = 1
for i in range(3,-1,-1):
    d[i] ^= x
    x &= d[i]
r = 0
for v in d[::-1]:
    r = 2*r + v
print(r)