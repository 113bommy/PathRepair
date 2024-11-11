n =  int(input())
l =  list(map(int,input().split()))
l1 = []
for i in range(n):
  for j in range(n-1-i,-1,-1):
    if l[j]==j+1:
      l1.append(l[j])
      del l[j]
      break
    else:
      continue
if len(l)==0:
  for j in l1[::-1]:
    print(j)
else:
  print(-1)