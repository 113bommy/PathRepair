a="CODEFESTIVAL2016"
s=input()
ans=0
for i in range(len(a)):
  if a[i]!=s[i]:
    ans+=1
print(ans)
