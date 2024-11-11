#解説読んだ

import math

N, L = list(map(int, input().split()))
T = [int(input()) for _ in range(N)]

K = N * (N - 1) * (N - 2) / 3 / 2
x, y = 0, 0
for i in range(N - 1):
  for j in range(i + 1, N):
    a = (T[i] + T[j]) / 2
    b = a + L / 2
    t = j - i - 1
    k = N - 2 - t
    x += k * math.cos(2 * math.pi * a / L) / K
    x += t * math.cos(2 * math.pi * b / L) / K
    y += k * math.sin(2 * math.pi * a / L) / K
    y += t * math.sin(2 * math.pi * b / L) / K
print(x, y)