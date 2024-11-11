from collections import Counter
n=int(input())
a=list(map(int,input().split()))
r=Counter([min(x//400,8) for x in a])
l=len(list(iter(r)))
if r[8]==0:
  print(l,l)
else:
  print(max(l-1,1),l-1+r[8])

