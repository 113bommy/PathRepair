from math import gcd
(n, m), x, p = [int(i) for i in input().split()], [int(i) for i in input().split()], [int(i) for i in input().split()]
gc = x[1] - x[0]
for i in range(len(x) - 1):
    gc = gcd(gc, abs(x[i] - x[i + 1]))
for i in range(len(p)):
    if gc % p[i] == 0:
        print("YES\n", x[0], ' ', i + 1, sep='')
        exit()
print("NO")