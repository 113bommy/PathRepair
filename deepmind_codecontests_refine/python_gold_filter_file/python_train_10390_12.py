import math

# input
#
# n = 5
# k = 10
# a = [1, 2, 3, 2, 3]

n, k = map(int, input().split())
a = [int(ai) for ai in input().split()]

# make jumpto
#
# 0 -> 6 (6)
# 1 -> 4 (3)
# 2 -> 5 (3)
# 3 -> 7 (4)
# 4 -> 8 (4)

jumpto = [[-1] * n]
la = -1
li = -1
for (ca, ci) in sorted(zip(a, range(n))):
    if ca == la:
        jumpto[0][ci] = jumpto[0][li] + li - ci
        jumpto[0][li] = ci - li + 1
    else:
        jumpto[0][ci] = n + 1
    la = ca
    li = ci

# doubling jumpto
#
# 0 -> 6 ->  9 (9)
# 1 -> 4 ->  8 (7)
# 2 -> 5 -> 11 (9)
# 3 -> 7 -> 10 (7)
# 4 -> 8 -> 12 (8)
#
# 0 -> 6 ->  9 -> 13 -> 17 (17)
# 1 -> 4 ->  8 -> 12 -> 15 (14)
# 2 -> 5 -> 11 -> 14 -> 18 (16)
# 3 -> 7 -> 10 -> 16 -> 19 (16)
# 4 -> 8 -> 12 -> 15 -> 21 (17)

levels = int(math.log(k, 2))
for l in range(1, levels + 1):
    jumpto.append([-1] * n)
    for i in range(n):
        f = jumpto[l - 1][i]
        s = jumpto[l - 1][(i + f) % n]
        jumpto[l][i] = f + s

# step1 and step2
ret = []
s = 0
while s < n * k:
    jumped = False
    for l in range(levels, -1, -1):
        if s + jumpto[l][s % n] <= n * k:
            s += jumpto[l][s % n]
            jumped = True
            break
    if not jumped:
        ret.append(str(a[s % n]))
        s += 1

print(' '.join(ret))
