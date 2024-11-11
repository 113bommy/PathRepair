n=int(input())
ans=0
check=0
for i in range(n):
  s=int(input())
  if i==n-1:
    check+=s
    ans+=check//2
  elif s!=0:
    check+=s
  else:
    ans+=check//2
    check=0
print(ans)
