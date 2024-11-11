import sys
from collections import Counter
from collections import defaultdict

sys.setrecursionlimit(10 ** 7)

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

CA = Counter(A)
CB = Counter(B)

right_idx = defaultdict(lambda: -1)
left_idx = defaultdict(lambda: -1)

for i in range(N):
    a = A[i]
    right_idx[a] = i

for i in range(N)[::-1]:
    b = B[i]
    left_idx[b] = i

# check
for X in [A, B]:
    for x in X:
        if CA[x] + CB[x] > N:
            print("No")
            exit()


shift = 0
for x in range(1, N + 1):
    if right_idx[x] == -1 or left_idx[x] == -1:
        continue

    shift = max(right_idx[x] - left_idx[x] + 1, shift)


ANS = B[-shift:] + B[:-shift]

print("Yes")
print(" ".join(map(str, ANS)))

