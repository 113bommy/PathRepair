n=int(input())
a=list(map(int,input().split()))
a.sort()
t=1
for i in a:
  t*=i
  if t>10**18:
    t=-1
    break
print(t)