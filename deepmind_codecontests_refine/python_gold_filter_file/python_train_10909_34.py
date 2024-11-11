n=int(input())
s=input()
ans=0
for i in range(1000):
  t=str(i).zfill(3)
  j=0
  for s_i in s:
    if j<3 and t[j]==s_i:
      j+=1
  if j==3:
    ans+=1
print(ans)