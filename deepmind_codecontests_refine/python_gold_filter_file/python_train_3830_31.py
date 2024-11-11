from bisect import bisect_right,bisect_left
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
an.sort()
ap.sort()
np,nn=len(ap),len(an)
if np*nn<k<=np*nn+zeronum*(zeronum-1)//2+zeronum*(np+nn):
  print(0)
else:
  #print(ap)
  #print(an)
  if k<=np*nn:
    ng=10**18
    ok=0
    while ng-ok>1:
      mid=(ok+ng)//2
      cnt=0
      for i in range(nn):
        if mid%an[i]!=0:
          cnt+=np-bisect_left(ap,mid//an[i]+1)
        else:
          cnt+=np-bisect_left(ap,mid//an[i])
      #print(cnt)
      if cnt>=k:
        ok=mid
      else:
        ng=mid
    print(-ok)
  else:
    k-=np*nn+zeronum*(zeronum-1)//2+zeronum*(np+nn)
    #print(k)
    ok=10**18
    ng=0
    #print(ok,ng)
    while ok-ng>1:
      mid=(ok+ng)//2
      cnt1,cnt2=0,0
      if np>=2:
        for i in range(np):
          cnt1+=bisect_right(ap,mid//ap[i])
          if ap[i]**2<=mid:
            cnt1-=1
      if nn>=2:
        for i in range(nn):
          cnt2+=bisect_right(an,mid//an[i])
          if an[i]**2<=mid:
            cnt2-=1
      if cnt1//2+cnt2//2>=k:
        ok=mid
      else:
        ng=mid
    print(ok)
