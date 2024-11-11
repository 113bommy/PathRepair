import sys
def get_ints(): return list(map(int, sys.stdin.readline().strip().split()))

def solve(N, K, X, A):
    prefix, suffix = [0] * (N + 2), [0] * (N + 2)
    for i in range(N):
        prefix[i + 1] = prefix[i] | A[i]

    for i in range(N - 1, -1, -1):
        suffix[i] = suffix[i + 1] | A[i]

    ans = 0
    val = X ** K
    for i in range(N):
        ans = max(
            ans,
            prefix[i] | A[i] * val | suffix[i + 1]
        )

    return ans

N, K, X = map(int, input().split())
A = get_ints()
print(solve(N, K, X, A))
