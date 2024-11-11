n=int(input())
s=input()
cnt=s.count(".")
ans=cnt
for i in s:
  if i==".":cnt -=1
  else:cnt +=1
  ans=min(ans,cnt)
print(ans)