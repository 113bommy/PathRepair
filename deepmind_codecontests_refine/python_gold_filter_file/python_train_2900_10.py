A = list(map(int, input().split()))
S = A[1]
S += (A[0] // 2) * 2 + (A[3] // 2) * 2 + (A[4] // 2) * 2
if A[3] % 2 == 1 and A[4] % 2 == 1 and A[0] % 2 == 1:
  S += 3
elif A[3] % 2 == 1 and A[4] % 2 == 1 and A[0] % 2 == 0 and A[0] != 0:
  S += 1
elif A[3] % 2 == 0 and A[4] % 2 == 1 and A[0] % 2 == 1 and A[3] != 0:
  S += 1
elif A[3] % 2 == 1 and A[4] % 2 == 0 and A[0] % 2 == 1 and A[4] != 0:
  S += 1
print(S)
