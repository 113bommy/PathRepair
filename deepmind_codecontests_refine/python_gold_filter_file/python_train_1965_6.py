import sys

l = [True] * 1000000
for i in range(2, 1000000):
    if (l[i - 1]):
        for j in range(i ** 2 - 1, 1000000, i):
            l[j] = False

for s in sys.stdin:
    print(l[1:int(s)].count(True))