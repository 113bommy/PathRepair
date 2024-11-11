n=int(input())
a=([int(n) for n in input().split()])
b=([int(n) for n in input().split()])
b.append(0)
r=0
t=0
x=0
for i in range(n+1):
  t=b[i]+x-a[i]
  if t>=0:
    r=r+a[i]
    x=min(b[i],t)
  else:
    r=r+b[i]+x
    x=0
print(r)