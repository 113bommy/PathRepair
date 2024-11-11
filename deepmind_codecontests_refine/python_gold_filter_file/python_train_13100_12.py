import collections
N=int(input())
L=list(map(int,input().split()))
ANS=[0,0]
c = collections.Counter(L).most_common()
    
for k,v in c:
  if v <= 1:
    break
  if v >= 4:
    ANS.append(k)
    ANS.append(k)
  else:
    ANS.append(k)

Z=sorted(ANS)
print(Z[-1]*Z[-2])