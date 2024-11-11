n=int(input())
a=[[list(map(int,input().split()))for _ in'_'*int(input())]for _ in'_'*n]
m=0
for i in range(2**n):
  *s,=map(int,bin(i)[2:].zfill(n))
  f=1
  for j,t in enumerate(a):
    if s[~j]:
      for x,y in t:f&=s[-x]==y
  m=max(m,sum(s)*f)
print(m)