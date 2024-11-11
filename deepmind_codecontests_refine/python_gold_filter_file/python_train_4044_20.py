n=int(input())
L=[2,1]
for i in range(n):
  l=L[i]+L[i+1]
  L.append(l)
print(L[n])