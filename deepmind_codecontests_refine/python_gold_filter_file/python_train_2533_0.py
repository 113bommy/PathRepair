import math
n = int(input())
p = n
factor = []
while n % 2 == 0:
    factor.append(2)
    n //= 2
for i in range(3, int(math.sqrt(p))+1, 2):
    while n % i == 0:
        factor.append(i)
        n //= i
if n != 1:
    factor.append(n)
total = p
for i in range(len(factor)):
    p = p // factor[i]
    total += p

print(total)