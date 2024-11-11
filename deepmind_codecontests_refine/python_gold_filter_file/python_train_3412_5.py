k=int(input())
s=7
i=1
while s%k!=0:
  i+=1
  s=10*(s%k)+7
  if i==k+1:
    break
else:
  print(i)
  exit()
print(-1)