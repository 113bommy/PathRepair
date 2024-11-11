n,*s=[t[:-1]for t in open(0)]
n=int(n)
c=0
for _ in range(n):
  c+=all(x==''.join(y)for x,y in zip(s,zip(*s)))*n
  s=s[1:]+s[:1]
print(c)