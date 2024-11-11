I,*U=N,*D=9**9,
P,*L='x+y,',
M,*R='x-y,',
for t in[*open(0)][1:]:*z,u=t.split();exec(u+'+=[*map(int,z)],')
for*A,S in(D,U,'x,y,'),(L,R,'y,x,'),(U,R,P+M),(L,D,P+M),(L,U,M+P),(D,R,M+P):
 for x,y,r in eval('sorted((%sQ)for Q,P in enumerate(A)for x,y in P)'%S):
  if r:S,p=x,y
  elif x==S:N=min(N,y-p)
print(N%I*5or'SAFE')