n=int(input())
a=list(map(int,input().split()))
ch=0

b=[0 for _ in range(8)]
for r in a:
  t=r//400
  if t>=8:
    ch+=1
  else:
    b[t]+=1
    
c=8-b.count(0)
print(str(max(1,c))+' '+str(c+ch))