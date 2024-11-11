from collections import defaultdict
n=input()
A=[int(i) for i in input().split()]
c=defaultdict(int)
free=0
for a in A:
  if a > 3199:
    free+=1
  else:
    c[a//400]+=1
print(max(len(c),1),len(c)+free)