from collections import Counter

n = int(input())
a = list(map(int, input().split()))

c = Counter()

for ai in a:
    l = len(str(ai))
    c[l] += 1

res = 0
mod = 998244353

for ai in a:
    s = str(ai)
    l = len(s)
    for key, value in c.items():
        if key >= l:
            eq = '0'.join(s)
            res = (res + int(eq)*value)%mod
            eq = '0'.join(s) + '0'
            res = (res + int(eq) * value) % mod
        else:
            eq = ''
            i = 0
            while i < key:
                eq = '0' + s[l-i-1] + eq
                i += 1
            eq = s[:l-i] + eq
            res = (res + int(eq) * value)%mod
            eq = '0'
            i = 0
            while i < key-1:
                eq += '0' + s[l - i - 1] + eq
                i += 1
            eq = s[:l-i] + eq
            res = (res + int(eq) * value) % mod

print(res)