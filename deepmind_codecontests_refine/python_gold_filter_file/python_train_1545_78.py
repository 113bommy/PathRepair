N=int(input())
L=[input() for i in range(N)]
M=int(input())
S=[input() for i in range(M)]
A=[0]
for i in range(N):
  A.append(L.count(L[i])-S.count(L[i]))
 
print(max(A))