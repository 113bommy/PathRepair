N = int(input())
S = list(input())
A = S.count("R") * S.count("G") * S.count("B")

for i in range(N):
  for j in range(i+1, N):
    k = j-i+j
    if k<N and S[k] != S[j] and S[k] != S[i] and S[i] !=S[j]:
      A -= 1    

print(A)
