N=int(input())
L=[2,1]
for n in range(2,N+1):
  L.append(L[n-1]+L[n-2])
print(L[-1])
