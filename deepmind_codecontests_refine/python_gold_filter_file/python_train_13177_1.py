import os,io
from sys import stdout
import collections
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def binomial_coefficient(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

def powerOfK(k, max):
    if k == 1:
        return [1]
    if k == -1:
        return [-1, 1]

    result = []
    n = 1
    while n <= max:
        result.append(n)
        n *= k
    return result

def prefixSum(arr):
    for i in range(1, len(arr)):
        arr[i] = arr[i] + arr[i-1]
    return arr

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

ps = [0] + prefixSum(a)
can = set([])
canMap = collections.defaultdict(int)

powers = powerOfK(k, 10**14)
result = 0
for e in ps:
    for p in powers:
        if e - p in can:
            result += canMap[e-p]
    can.add(e)
    canMap[e] += 1

print(result)
