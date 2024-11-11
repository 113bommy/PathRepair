n=int(input())
ans=0
a=0
b=0
flg=1
for _ in range(n):
  s=input()
  for i in range(len(s)-1):
    if s[i:i+2]=="AB":
      ans+=1
  if s[0]=="B":
    b+=1
    if s[-1]!="A":
      flg=0
  if s[-1]=="A":
    a+=1
    if s[0]!="B":
      flg=0
if flg:
  ans+=max(0,min(a,b)-1)
else:
  ans+=min(a,b)
print(ans)