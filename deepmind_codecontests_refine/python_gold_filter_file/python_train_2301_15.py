n,k=map(int,input().split())
li=list(map(int,input().split()))
m=0
for i in list(set(li)):
 if li.count(i)>m:
  m=li.count(i)
dishes=0
if m%k==0:
 dishes=m
else:
 s=(m+k-1)//k
 dishes=k*s
print((dishes*len((set(li))))-n)
