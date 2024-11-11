n,d=map(int,input().split())
l=[]
for i in range(d):
  s=input()
  l.append(s)
cnt=0
cnt1=0
z=[]
for j in range(len(l)):
  if "0" in l[j]:
    cnt+=1
  else:
    z.append(cnt)
    cnt=0
if len(z)==0:
  print(cnt)
else:
  print(max(max(z),cnt))
  