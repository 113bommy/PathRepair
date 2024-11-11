n,x=map(int,input().split())
a=[(1,1)]
for _ in range(n):
  a+=[(a[-1][0]*2+3,a[-1][1]*2+1)]

if a[-1][0] in (x,x-1):
  print(a[-1][1])
  exit()
a=a[:-1]
s=0
for k in range(1,len(a)*2+1):
  i,j = a[-k // 2]
  x -= k % 2
  if i <= x:
    x-=i;s+=j
    if x>=1:
      x-=1;s+=1

print(s)
