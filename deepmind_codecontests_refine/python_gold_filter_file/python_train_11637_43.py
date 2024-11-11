from sys import stdin
from random import randint
from time import time
input = lambda: stdin.readline().rstrip()
start = time()
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
b.reverse()
ok = 0
t = time() - start
while t < 1.8:
    cnt = 0
    for i in range(n):
        if a[i] == b[i]:
            rng = randint(0, n - 1)
            b[i], b[rng] = b[rng], b[i]
            cnt += 1
    if cnt == 0:
        ok = 1
        break
    t = time() - start
if ok == 1:
    print("Yes")
    print(*b)
else:
    print("No")
