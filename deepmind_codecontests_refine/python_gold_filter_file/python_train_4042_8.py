import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

if N%2 == 0:
    lower = A[:N//2]
    upper = A[N//2:]
    x = 2 * sum(upper) - upper[0]
    y = 2 * sum(lower) - lower[-1]
    answer = x - y
else:
    lower = A[:N//2]
    upper = A[N//2+1:]
    mid = A[N//2]
    x = 2 * sum(upper) - 2 * sum(lower) - mid + lower[-1]
    y = 2 * sum(upper) - 2 * sum(lower) + mid - upper[0]
    answer = max(x,y)
print(answer)