n=int(input())
ans="No"
for i in range(n//7+1):
  if (n-7*i)%4==0:
    ans="Yes"
    
print(ans)