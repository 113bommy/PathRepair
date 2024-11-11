import sys
input = sys.stdin.readline
n,r=map(int,input().split())
ABP,ABN=[],[]
for i in range(n):
  a,b=map(int,input().split())
  if b>=0:
    ABP.append([a,b])
  else:
    ABN.append([a,b])
ABP.sort(key=lambda x:(x[0],x[1]))
chk=True
for i in range(len(ABP)):
  if ABP[i][0]>r:
    chk=False
  else:
    r+=ABP[i][1]
if chk==False:
  print("NO")
else:
  ABN.sort(key=lambda x:(x[0]+x[1],x[0]),reverse=True)
  for i in range(len(ABN)):
    a,b=ABN[i]
    if r<a:
      chk=False
    else:
      r+=b
  if chk==False or r<0:
    print("NO")
  else:
    print("YES")
