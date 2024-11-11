import bisect
N = int(input())
A = sorted(list(map(int, input().split())))

ans = 0
for k in range(N-1,1,-1):
    if A[k]==int(A[k]):
        b = 1
        while b <= A[k]:
            b *= 2
        p = bisect.bisect_left(A,b-A[k])
        if p != k and A[p]+A[k] == b:
            ans += 1
            A[k] += 0.9
            A[p] -= 0.9
print(ans)
