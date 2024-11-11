import math
string = input()
a, b, n = map(int, string.split())
p = 0
while n ** p < a:
    p += 1
q = 0
while n ** q < b:
    q += 1
if n ** q > b:
    q -= 1
if p > q:
    print(-1)
else:
    for x in range(p, q + 1):
        print(n ** x, end = " ")