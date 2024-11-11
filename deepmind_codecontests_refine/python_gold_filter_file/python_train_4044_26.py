L = [2, 1]
for i in range(85):
  L.append(L[i]+L[i+1])
A = int(input())
print(L[A])
