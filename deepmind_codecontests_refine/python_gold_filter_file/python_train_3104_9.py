from collections import Counter


N, M = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()
A_cnt = Counter(A)
B_cnt = Counter(B)
if len(A) > 0:
    if max(A_cnt.values()) > 1:
        print(0)
        exit()
if len(B) > 0:
    if max(B_cnt.values()) > 1:
        print(0)
        exit()
if A[N - 1] != N * M or B[M - 1] != N * M:
    print(0)
    exit()

a = 0
b = 0
i = 1
C = [0] * (N * M)
while i <= N * M:
    if i == A[a] and i == B[b]:
        C[i - 1] = 1
        a += 1
        b += 1
    elif i == A[a] and i != B[b]:
        C[i - 1] = M - b
        a += 1
    elif i != A[a] and i == B[b]:
        C[i - 1] = N - a
        b += 1
    else:
        C[i - 1] = (N - a) * (M - b) - (N * M - i)
    i += 1

ans = 1
mod = 10 ** 9 + 7
for c in C:
    ans = (ans * c) % mod

print(ans)
