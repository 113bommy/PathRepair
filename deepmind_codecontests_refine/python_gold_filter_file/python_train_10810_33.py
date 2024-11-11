s = input()
ans=0
for i in range(len(s)//2):
  if s[:i]==s[i:2*i]:
    ans=2*i
print(ans)