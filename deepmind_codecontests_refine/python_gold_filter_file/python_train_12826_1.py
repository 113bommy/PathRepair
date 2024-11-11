import sys

n, k = map(int, input().split())
k1 = 0
k2 = 0
b1 = 0
b2 = 0
for i in range(k + 1):
    print('?', end=' ')
    for j in range(k + 1):
        if i != j:
            print(j + 1, end=' ')
    sys.stdout.flush()
    a, x = map(int, input().split())
    if i == 0:
        b1 = x
    if x == b1:
        k1 += 1
    else:
        b2 = x
        k2 += 1
if b1 > b2:
    print('!', k1)
else:
    print('!', k2)
sys.stdout.flush()