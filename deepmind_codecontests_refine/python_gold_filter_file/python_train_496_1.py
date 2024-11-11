n,k=map(int,input().split())
s=input()
t=s[::-1]
u="".join([s,t])
ls=[]
for i in range(n):
  ls.append(u[i:i+n])
ls.sort()
k-=1
x=ls[0]
cnt=1
for i in range(1,n):
  if x[0]==x[i]:
    cnt+=1
  else:
    break
if cnt*2**k<n:
  y=n-cnt*2**k
  print(x[0]*(cnt*2**k)+x[cnt:y+cnt])
else:
  print(x[0]*n)
