from fractions import gcd

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
zeros = 0

freqset = set()
freqdict = dict()

for i in range(n):
    if a[i] == 0 and b[i] != 0:
        continue
    elif a[i] == 0 and b[i] == 0:
        zeros += 1
        continue
    else:
        c = gcd(a[i], b[i])
        b[i], a[i] = b[i] // c, a[i] // c
    if (b[i], a[i]) not in freqset:
        freqset.add((b[i], a[i]))
        freqdict[(b[i], a[i])] = 1
    else:
        freqdict[(b[i], a[i])] += 1

r = freqdict.values()
if len(r) == 0:
    print(0 + zeros)
else:
    print(max(r) + zeros)