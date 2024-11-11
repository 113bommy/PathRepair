import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))
ap,an=[],[]
zeronum=0
for i in range(n):
  if a[i]>0:
    ap.append(a[i])
  elif a[i]<0:
    an.append(-a[i])
  else:
    zeronum+=1
np,nn=len(ap),len(an)
def fminus(x):
  j=0
  cnt=0
  for i in range(np):
    cnt+=j
    while j<nn and an[j]*ap[i]>=x:
      j+=1
      cnt+=1
  return cnt
def fplus(x,length,lis):
  r=length-1
  cnt=0
  for l in range(length):
    while lis[r]*lis[l]>x:
      if r==l:
        break
      r-=1
    if r==l:
      break
    elif lis[r]*lis[l]<=x:
      cnt+=r-l
  return cnt
if np*nn<k<=np*nn+zeronum*(zeronum-1)//2+zeronum*(np+nn):
  print(0)
else:
  #print(ap)
  #print(an)
  if k<=np*nn:
    an.sort(reverse=True)
    ap.sort()
    ng=10**18
    ok=0
    while ng-ok>1:
      mid=(ok+ng)//2
      if fminus(mid)>=k:
        ok=mid
      else:
        ng=mid
    print(-ok)
  else:
    an.sort()
    ap.sort()
    k-=np*nn+zeronum*(zeronum-1)//2+zeronum*(np+nn)
    #print(k)
    ok=10**18
    ng=0
    #print(ok,ng)
    while ok-ng>1:
      mid=(ok+ng)//2
      if fplus(mid,nn,an)+fplus(mid,np,ap)>=k:
        ok=mid
      else:
        ng=mid
    print(ok)