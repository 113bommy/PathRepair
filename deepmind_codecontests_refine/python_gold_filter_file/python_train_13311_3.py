import math
N = int(input())
A = 100000
for _ in range(N):
    A = A * 1.05
    A = (int(math.ceil(A / 1000))) * 1000
print(A)

