n=int(input())
s=input()
c=[]
cnt=1
for i in range(1,n):
  if s[i]==s[i-1]:
    cnt+=1
  else:
    c.append(cnt)
    cnt=1
c.append(cnt)
ans=len(c)
y=len(c)-c.count(1)
if y>=2:
  ans+=2
elif y==1:
  if max(c)>=3:
    ans+=2
  else:
    ans+=1
print(ans)