import sys
n,k=map(int,input().split())
c=0
if k*(k-1) < n:
 print('NO')
else:
 print('YES')
 for i in range(k-1):
  for j in range(k):
   c+=1
   if c>n:sys.exit()
   print(1+j,1+(j+i+1)%k)
