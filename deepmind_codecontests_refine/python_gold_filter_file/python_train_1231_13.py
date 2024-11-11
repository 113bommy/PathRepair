n,h=map(int,input().split())
a,b=[],[]

for i in range(n):
  inp=list(map(int,input().split()))
  a.append(inp[0])
  b.append(inp[1])

am=max(a)
b.sort()
b.reverse()
c=0
for i in b:
  if i<am:
    break
  c+=1
  h-=i
  if h<=0:
    break
c+=max((h-1)//am+1,0)
print(c)