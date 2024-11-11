from math import*
n = int(input())
b = list(map(int, input(). split()))
c = list(map(int, input(). split()))
k = {}
mx = 0
q = 0
for i in range(n):
    if b[i] == 0 and c[i] == 0:
        q += 1
        continue
    if b[i] == 0:
        continue
    x, y = b[i] // gcd(abs(c[i]), abs(b[i])), -c[i] // gcd(abs(c[i]), abs(b[i]))
    if x != abs(x) and x != 0:
        x *= -1
        y *= -1
    if str(x) + " " + str(y) in k:
        k[str(x) + " " + str(y)] += 1
    else:
        k[str(x) + " " + str(y)] = 1
    mx = max(mx, k[str(x) + " " + str(y)])
print(mx + q)
