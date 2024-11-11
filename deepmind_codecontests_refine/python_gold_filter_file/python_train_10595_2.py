s,k=input().split();k,o,c,z,L,O=int(k),s.count("1")+1,0,0,[],998244353;M,r=min(o,k+1),range
for i in s:
 if i=="0":L+=[c];c=0
 else:c+=1
d=[[0]*M for _ in r(o)];d[0][0]=1
for i in L:
 D=[[0]*M for _ in r(o)]
 for j in r(o):
  for l in r(max(z+i-j,0),o-j):
   m=max(l-i,0)
   for p in r(min(j+1,M-m)):D[j+l][p+m]=(D[j+l][p+m]+d[j][p])%O
 z+=i;d=D
print(sum([sum(i)for i in d])%O)