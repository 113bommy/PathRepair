
from collections import Counter

d = int(input())
l = []
for k in range(d):
  r = input()
   
  l.append(Counter(r))

oi = l[0]

for g in range(1,d):
    oi = oi & l[g]
    
    
print("".join(sorted(oi.elements())))

