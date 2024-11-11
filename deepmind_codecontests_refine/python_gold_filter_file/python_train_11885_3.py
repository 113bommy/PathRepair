n,m=map(int,input().split())
a=[[*map(int,input().split())] for _ in range(m)]
def g():
 for z in range(2):
  x=a[0][z]
  for i in range(m):
   if x not in a[i]: break
  else:
   return 0
  for w in range(2):
   y=a[i][w]
   for j in range(m):
    if x not in a[j] and y not in a[j]: break
   else:
    return 0
 return 1
print("YNEOS"[g()::2])