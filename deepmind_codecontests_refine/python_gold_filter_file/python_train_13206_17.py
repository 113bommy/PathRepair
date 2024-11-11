s=input()
a=s[0]
ans=0
for i in s[1:]:
  if i!=a:
    ans+=1
    a=i
print(ans)