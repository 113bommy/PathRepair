s,t=input(),input()
ls=len(s)
lt=len(t)
ans=''
for i in range(ls-lt+1)[::-1]:
  c=0
  for j in range(lt):
    if s[i+j]==t[j] or s[i+j]=='?':
      c+=1
  if c==lt:
    ans=s[:i]+t+s[i+lt:]
    print(ans.replace('?','a'))
    break
else:
  print('UNRESTORABLE')