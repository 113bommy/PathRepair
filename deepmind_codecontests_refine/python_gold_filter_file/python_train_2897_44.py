n=int(input())
s=[list(input()) for i in range(n)]
ans=0
for i in range(n):
  ct=0
  for j in range(n):
    for k in range(n):
      if s[(j+i)%n][k]==s[(k+i)%n][j]:
        ct+=1
  if ct==n**2:
    ans+=1
print(ans*n)