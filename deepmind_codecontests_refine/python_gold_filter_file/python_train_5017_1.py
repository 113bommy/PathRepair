n = int(input())
a = input().split()
b = input().split()

indices = dict()
for i in range(n):
  car = b[i]
  indices[car] = i

aux = 0
finned = 0
for i in range(n):
  ath_at_b = indices[a[i]]
  aux = max(aux, ath_at_b)
  if ath_at_b < aux:
    finned += 1 

print(finned)