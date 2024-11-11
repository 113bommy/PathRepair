N=int(input())
A=list(map(int,input().split()))
Aabs=list(map(abs,A))

fu=0
for i in range(N):
  if A[i]<0:
    fu+=1
if fu % 2 == 0:
  print(sum(Aabs))
else:
  print(sum(Aabs)-2*min(Aabs))