#572_C

import math

l = int(input())

s = 0

a = [0]

ln = [int(i) for i in input().split(" ")]

for i in range(0, l):
    s += ln[i]
    a.append(s)

q = int(input())

for i in range(0, q):
    ln2 = [int(j) for j in input().split(" ")]
    num = a[ln2[1]] - a[ln2[0] - 1]
    print(math.floor(num / 10))
