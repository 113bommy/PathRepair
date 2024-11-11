N = int(input())
A = list(map(int, input().split()))

A.sort()
res = 0

for i in range(1, N):
    res += A[N-(i//2)-1]

print(res)