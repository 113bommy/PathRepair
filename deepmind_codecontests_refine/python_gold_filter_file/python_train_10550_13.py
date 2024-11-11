import math
n = int(input())

k = int(math.sqrt(2*n))

check = False

for i in range(k, 0, -1):
    p = n - i*(i+1)//2
    if p <= 0:
        continue

    sqrt_p = int(math.sqrt(2*p))

    if sqrt_p*(sqrt_p + 1)//2 == p:
        check = True
        break

if check:
    print("YES")
else:
    print("NO")
