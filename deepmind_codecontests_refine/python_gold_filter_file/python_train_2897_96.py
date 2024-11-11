import sys
from itertools import product

read = sys.stdin.read
readline = sys.stdin.readline

N, *S = map(str, read().split())
N = int(N)
x = 0
answer = 0
for y in range(N):
    for i, j in product(range(N), repeat=2):
        if S[(i + x) % N][(j + y) % N] != S[(j + x) % N][(i + y) % N]:
            break
    else:
        answer += N

print(answer)
