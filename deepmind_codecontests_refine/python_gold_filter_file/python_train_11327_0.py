from collections import*
n,m,*d=map(int,open(0).read().split())
a=Counter(d[:n])
for b,c in zip(d[n::2],d[n+1::2]):a[c]+=b
s=0
for k, v in sorted(a.items())[::-1]:
 if n<v:exit(print(s+k*n))
 n-=v
 s+=k*v