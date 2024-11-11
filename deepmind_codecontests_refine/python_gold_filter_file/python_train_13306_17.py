import math
l = int(input())
r = math.floor(math.log2(l))
n = r+1
pow2r = pow(2, r)
lst = list([i, i+1, 0] for i in range(1, n)) + list([i, i+1, pow(2, i-1)] for i in range(1, n))
for i in range(1, n)[::-1]:
    p = pow(2, i-1)
    if l - p >= pow2r:
        lst.append([i, n, l-p])
        l -= p
print(n, len(lst))
for u, v, w in lst:
    print(u, v, w)