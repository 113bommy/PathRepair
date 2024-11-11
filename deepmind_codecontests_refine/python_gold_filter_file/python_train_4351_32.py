a=[list(map(int,input().split())) for i in range(3)]
n=int(input())

for i in range(n):
  b=int(input())
  for j in range(3):
    for k in range(3):
      if a[j][k]==b:
        a[j][k]=-1

ans='No'
for i in a:
  if list(i)==[-1,-1,-1]:
    ans='Yes'
for i in zip(*a):
  if list(i)==[-1,-1,-1]:
    ans='Yes'
if a[0][0]+a[1][1]+a[2][2]==-3:
  ans='Yes'
if a[0][2]+a[1][1]+a[2][0]==-3:
  ans='Yes'


print(ans)