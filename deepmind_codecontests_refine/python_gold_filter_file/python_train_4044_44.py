L=[2,1]
for i in range(86):
  L.append(L[-1]+L[-2])
print(L[int(input())])