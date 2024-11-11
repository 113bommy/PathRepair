n=int(input())
t='ACGT'
a=[*input()]
b=[n//4-a.count(x)for x in t]
i=j=0
for j in range(4):
  while b[j]:
    if '?' not in a:break
    a[a.index('?')]=t[j]
    b[j]-=1
  else:continue
  break
print([''.join(a),'===']['?'in a or b!=[0]*4])