s=input()
c=0
ans=0
for i in range(len(s)):
  if s[i]=='T':
    c+=1
  if s[i]=='S':
    c-=1
  ans = max(ans,c)
print(ans*2)
