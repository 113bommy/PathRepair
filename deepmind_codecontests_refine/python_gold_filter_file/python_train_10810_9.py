s=input()
ans = 0
for i in range(len(s)//2):
  if s[:i]==s[i:i*2]:
    ans=i*2
print(ans)