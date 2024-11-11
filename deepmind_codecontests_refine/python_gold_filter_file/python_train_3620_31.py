d=[[],[],[],[]]
for t in[*open(0)][1:]:*z,u=t.split();d[ord(u)%5]+=[*map(int,z)],
I=N=9**9
P,M='x+y,','x-y,'
for*A,S in(3,0,'x,y,'),(1,2,'y,x,'),(0,2,P+M),(1,3,P+M),(1,0,M+P),(3,2,M+P):
 n=p=-I
 for x,y,r in eval('sorted((%sQ)for Q,P in enumerate(A)for x,y in d[P])'%S):
  if r:n,p=x,y
  elif x==n:N=min(N,y-p)
print(N%I*5or'SAFE')