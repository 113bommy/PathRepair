from bisect import*
A,B=abs,bisect
a,b,q,*l=map(int,open(0).read().split())
f=2**60
s,t=[-f]+l[:a]+[f],[-f]+l[a:a+b]+[f]
for x in l[a+b:]:
  m=f
  i,j=B(s,x),B(t,x)
  for v in s[i-1:i+1]:
    for w in t[j-1:j+1]:
      m=min(m,A(x-v)+A(v-w),A(x-w)+A(w-v))
  print(m)