n,m=map(int,input().split())
a=[input() for i in range(n)]
b=[input() for i in range(m)]
ans="No"
for i in range(n-m+1):
  for j in range(n-m+1):
    if [line[j:j+m] for line in a[i:i+m]]==b:
      ans="Yes"
      break
  if ans=="Yes":
    break
print(ans)