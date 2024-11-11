import sys,io,os
z=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
M=998244353
n,k=map(int,z().split())
s=[]
e=[]
v=[1]
v2=[]
for i in range(1,n+1):v.append((v[-1]*i)%M)
v2.append(pow(v[-1],M-2,M))
for i in range(n):v2.append((v2[-1]*(n-i))%M)
v2=v2[::-1]
for i in range(n):
 a,b=map(int,z().split())
 s.append(a)
 e.append(b)
s.sort()
e.sort()
s.append(2*M)
e.append(2*M)
si=ei=t=r=0
while si+ei<n+n:
 while si<n and s[si]<=e[ei]:
  si+=1
  t+=1
 while ei<n and e[ei]<s[si]:
  ei+=1
  t-=1
  if t>=k-1:r=(r+(v[t]*v2[k-1])%M*v2[t-k+1])%M
print(r)