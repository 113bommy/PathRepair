N = int(input())
A = list(map(int, input().split()))

def sol(S):
    ret = 0
    for a in A[1:]:
        b = a
        if S * (S + b) > 0:
            b = (abs(S) + 1) * (1 if S < 0 else -1)
        if S + b == 0:
            b = b - 1 if S > 0 else b + 1
        ret += abs(b - a)
        S += b
    return ret

if A[0] == 0:
    ans = min(sol(1), sol(-1)) + 1
else:
    ans = min(sol(A[0]), sol(-A[0] // abs(A[0])) + abs(A[0]) + 1)
print(ans)
