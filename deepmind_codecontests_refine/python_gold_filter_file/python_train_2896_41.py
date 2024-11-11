n,k=map(int,input().split())
a=list(map(int,input().split()))
s=[0]
for i in range(n):
  s.append(s[-1]+a[i])
l=[]
for i in range(1,n+1):
  for j in range(i):
    l.append(s[i]-s[j])
l.sort(reverse=True)
m=61
ans=0
chk=0
for i in range(m)[::-1]:
  cnt=0
  chk+=2**i
  for j in l:
    if chk & j == chk:
      cnt+=1
  if cnt < k:
    chk-=2**i
print(chk)