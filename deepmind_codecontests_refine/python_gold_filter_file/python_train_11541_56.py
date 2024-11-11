a,b,c=map(int,input().split())
ans="NO"
for i in range(b):
  if a*(i+1)%b==c:ans="YES"
print(ans)