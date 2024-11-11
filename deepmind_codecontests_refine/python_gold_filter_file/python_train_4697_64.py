A = list(map(int, input().split()))
A.sort()
a = int(A[2] - (A[1] + A[0]))
if a >= 0:
  print(a+1)
else:
  print(0)