for s in[*open(0)][1:]:
 n,a,b=map(int,s.split());r=-1,
 if-2<a-b<2and a+b<n-1:
  *r,=range(1,n+1);j=a>=b;k=a>b
  for i in[*range(2-j,a+b-k+j,2)]+([(n-2)*k],[])[a==b]:r[i:i+2]=r[i+1],r[i]
 print(*r)