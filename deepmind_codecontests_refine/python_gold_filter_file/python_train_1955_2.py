from collections import defaultdict
from decimal import Decimal
N = int(input())
T = defaultdict(int)
a = 0
b = 0
for i in range(N):
    A = Decimal((input()))
    A *= 10**9
    A = int(A)
    t = 0
    f = 0
    while(True):
        if A % 2 != 0:
            break
        A = A // 2
        t += 1
    while (True):
        if A % 5 != 0:
            break
        A = A // 5
        f += 1
    T[(t, f)] += 1
    a = max(a, t)
    b = max(b, f)

ans = 0
for k, v in T.items():
    for i in range(18-k[0], a+1):
        for j in range(18-k[1], b+1):
            if (i, j) in T:
                if k[0] == i and k[1] == j:
                    ans += v * (v-1)
                else:
                    ans += v * T[(i, j)]
print(ans//2)