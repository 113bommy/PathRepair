n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
sp=sn=0
P=[]
a=0
for i in range(n):
  d=A[i]-B[i]
  if d<0:
    sn+=d
    a+=1
  else:
    sp+=d
    P.append(d)
if sp<-sn:
  print(-1)
  exit()
for p in sorted(P)[::-1]:
  if sn>=0:
    break
  else:
    sn+=p
    a+=1
print(a)