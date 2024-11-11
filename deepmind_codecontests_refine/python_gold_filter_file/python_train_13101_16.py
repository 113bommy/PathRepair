n,c,k=map(int,input().split())
t=[]
for _ in range(n):
  t.append(int(input()))
t.sort()
renow=0
cun=0
for i in range(n):
  if t[i]-t[renow]>k:
    cun+=1
    renow=i
  if i-renow+1>=c:
    cun+=1
    renow=i+1
if renow>=n:
  print(cun)
else:
  print(cun+1)
  
