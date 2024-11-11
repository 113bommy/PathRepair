A=[]
p = int(input())
for i in range(p):
  j,k = input().split()
  A.append([j,-int(k),i+1])
A = sorted(A)
for j,k,l in A:
  print(l)