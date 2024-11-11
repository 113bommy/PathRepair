import math
import sys
def newt(n,k):
  return (math.factorial(n)//math.factorial(k))//math.factorial(n-k)
def go(occ,used):
  # print(occ,used)
  cnt=[0]*20
  cnt[0]=1
  for digit,rep in enumerate(occ):
    if cnt==0 or rep==0:
      continue
    res=[0]*20
    r=range(rep+1) if digit==used else range(1,rep+1)
    for i in r:

      for j,x in enumerate(cnt):
        if i+j>=20:continue
        res[i+j]+=x*newt(j+i,i)
    cnt=res
  return sum(cnt)


n=input()
occ = [ n.count(str(x)) for x in range(10)]
ans=0
for i in range(1,10):
  if occ[i]>0:
    occ[i]-=1
    ans+=go(occ,i)
    occ[i]+=1
print(ans)