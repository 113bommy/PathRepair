s=input()

n=len(s)
ans="NO"

for i in range(n):
  for j in range(1,n+1):
    num=s[:i]+s[j:]
    if num == "keyence":
      ans="YES"
      
print(ans)
