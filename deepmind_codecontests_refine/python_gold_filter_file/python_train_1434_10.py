N=int(input())
j=0
J=0
for i in range(N):
  D1,D2=map(int,input().split())
  if D1==D2:
    j+=1
    if j>=3:
      J=3
  else:
    j=0
if J>=3:
  print('Yes')
else:
  print('No')