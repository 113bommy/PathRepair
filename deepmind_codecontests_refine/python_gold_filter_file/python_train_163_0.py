n, k, p = [int(i) for i in input().split()]

A = [int(i) for i in input().split()]

B = [int(i) for i in input().split()]


A.sort()
B.sort()

ans = 10**18

for start in range(k):
    curmax = 0
    curans = 10**18
    if start+n > k:
        continue
    for i in range(n):
        curmax = max(curmax, abs(A[i] - B[start+i]) + abs(B[start+i] - p))

    ans = min(ans, curmax)

print(ans)

