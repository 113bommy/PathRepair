modulo = 998244353
from collections import Counter

def conv(x):
    res = 0
    for v in x:
        res = (res * 100 + int(v)) % modulo
    return res
 
n = int(input())
x = list(input().split())
c = Counter(len(v) for v in x)
res = 0
for v in x:
    u = len(v)
    for w, k in c.items():
        if w >= u:
            res += k * 11 * conv(v)
        else:
            d = u - w
            res += k * 11 * conv(v[d:])
            res += k * 2 * int(v[:d]) * (10 ** (2*w))
    res %= modulo        
print(res)
