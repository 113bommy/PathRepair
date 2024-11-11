from collections import deque, defaultdict
from time import time
S = time()

N = int(input())
A = [deque(map(lambda a: int(a) - 1, input().split())) for _ in range(N)]

canBattle = defaultdict(lambda: False)
D = [0] * N

while True:
    isChanged = False
    for i, a in enumerate(A):
        if not a:
            continue
        j = a[0]
        canBattle[(i, j)] = True

        if canBattle[(j, i)]:
            isChanged = True
            A[i].popleft()
            A[j].popleft()
            d = max(D[i], D[j])
            D[i], D[j] = d + 1, d + 1
    if all(len(a) == 0 for a in A):
        print(max(D))
        exit()
    if time() - S >= 1.700:
        print(N * (N - 1) // 2)
        exit()
    if not isChanged:
        break

print(-1)
