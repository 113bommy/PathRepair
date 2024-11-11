N = int(input())
A = list(map(int, input().split()))

MAX_ABS = 0
MAX_ABS_NUMBER = 0
MAX_ABS_NUMBER_INDEX = 1

for i, a in enumerate(A, start=1):
    if abs(a) > MAX_ABS:
        MAX_ABS = abs(a)
        MAX_ABS_NUMBER = a
        MAX_ABS_NUMBER_INDEX = i


if MAX_ABS_NUMBER >= 0:
    print(2 * N - 1)
    for i in range(1, N + 1):
        print(MAX_ABS_NUMBER_INDEX, i)
    for i in range(1, N):
        print(i, i + 1)

else:
    print(2 * N - 1)
    for i in range(1, N + 1):
        print(MAX_ABS_NUMBER_INDEX, i)
    for i in range(N, 1, -1):
        print(i, i - 1)
