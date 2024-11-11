n = int(input())
A = list(map(int, input().split()))
C = []
T = False
i = 0
k = 0
while i < n:
    if A[i] != i:
        a = (max(A[i], i), min(A[i], i))
        C.append(a)
    else:
        k += 1
    i += 1
C.sort()
for i in range(len(C) - 1):
    if C[i] == C[i + 1]:
        T = True
        break
if n == k:
    print(k)
elif T:
    print(k + 2)
else:
    print(k + 1)
