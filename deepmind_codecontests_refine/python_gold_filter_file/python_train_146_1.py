import sys

n = int(sys.stdin.readline())
weights = list(map(int, sys.stdin.readline().split()))

sum = 0
h = False
for w in weights:
    if w == 100:
        h = True
    sum = abs(sum - w)

print('YES' if (h and sum == 200) or sum == 0 else 'NO')
