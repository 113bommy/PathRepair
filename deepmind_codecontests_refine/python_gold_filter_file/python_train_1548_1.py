N = int(input())
A = [int(input()) for _ in range(2**N)]

while len(A) > 1:
  B = []
  i = 0
  while i+1 < len(A):
    if A[i] == A[i+1]:
      B.append(A[i])
    else:
      B.append(abs(A[i] - A[i+1]))      
    i += 2
  A = B
print(A[0])