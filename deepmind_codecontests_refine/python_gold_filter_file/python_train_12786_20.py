n=int(input())
ans="No"
for i in range(n//7+1):
  if (n-i*7)%4==0:
    ans="Yes"
    break
print(ans)