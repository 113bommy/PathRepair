import bisect

N = int(input())

A = list(map(int, input().split()))

A.sort()

ans = 0
for a in range(N-2):
    for b in range(a+1, N-1):
        ans += bisect.bisect_left(A, A[a]+A[b])-b-1

print(ans)