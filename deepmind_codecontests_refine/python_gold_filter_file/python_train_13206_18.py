s=input()
ans=0
for i in range(len(s)-1):
  if s[i+1]!=s[i]:
    ans+=1
print(ans)