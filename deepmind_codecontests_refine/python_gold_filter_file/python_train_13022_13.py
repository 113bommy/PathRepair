n,m = map(int, input().split(" "))
t=n
l1=[0]*(m+1)
while t:
  l,r = map(int, input().split(" "))
  for i in range(l,r+1):
    l1[i]+=1
  t-=1
ct=0
for i in range(1,m+1):
  if l1[i]==0:
    ct+=1
print(ct)
for i in range(1,m+1):
  if l1[i]==0:
    print(i, end=' ')