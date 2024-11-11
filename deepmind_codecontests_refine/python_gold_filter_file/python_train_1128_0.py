n=int(input())
a=list(map(int,input().split()))
c=[0,0,0,0,0,0,0,0]
f=0
for i in a:
  if i//400<8:
    c[i//400]=1
  else:
    f+=1
ans=0
for i in c:
  ans+=i
print(max(1,ans),ans+f)