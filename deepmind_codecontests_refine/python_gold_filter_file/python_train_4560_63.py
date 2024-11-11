# いきぬきreview　忘れた問題
# gluttony
N, K = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))
F.sort()
A.sort(reverse=True)


def func(X):
    s = 0
    for i in range(N):
        a, f = A[i], F[i]
        s += max(0, a-X//f)
    return s <= K


R = 10**12
L = -1
while R-L > 1:
    m = (R+L)//2
    if func(m):
        R = m
    else:
        L = m
print(R)