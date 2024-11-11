import bisect
n = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = sorted([A[i] - B[i] for i in range(n)])
ans = 0
for i in range(n-1):
    if C[i] < 0:
        ans += (n - bisect.bisect_left(C,-C[i]+0.5, lo=i+1))
    elif C[i] == 0:
        ans += (n - bisect.bisect_left(C, 0.5, lo=i+1))
    else:
        ans += (n-i) * (n-i-1) // 2
        break
print(ans)
