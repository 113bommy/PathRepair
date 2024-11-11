n,m,*t=map(int,open(0).read().split())
s=sorted
a=s(t[:n])[::-1]
i=n
for c,b in s(zip(t[n+1::2],t[n::2]))[::-1]:
 while c>a[i-1]and i*b:a[i-1]=c;b-=1;i-=1
print(sum(a))