import collections
n = int(input())
s = collections.Counter(input()).values()
t = 1
for i in s:
    t = t * (i + 1) % (10 ** 9 + 7)
print((t - 1))
