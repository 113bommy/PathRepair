x = int(input())
L = [i for i in input().split()]
L.sort(key=int)
L2 = []

for i in range(len(L)):
   if i%2 == 0:
      L2.append(L[0])
      L.pop(0)
   else:
      L2.append(L[-1])
      L.pop(-1)      
      
S = " ".join(L2)
print(S)