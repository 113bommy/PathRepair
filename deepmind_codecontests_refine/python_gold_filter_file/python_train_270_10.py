import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, sys.stdin))
b = [0, 1, 1, 0]

for x in a:
    if b[x] == 0:
        print('NO')
        break
    for i in range(1, 4):
        if i != x:
            b[i] ^= 1
else:
    print('YES')
