n=int(input())
L=[2,1]
for i in range(n):
    L.append(L[i]+L[i+1])
print(L[n])