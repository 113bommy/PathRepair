k=int(input())
if k%2<1 or k%5<1:
  print(-1)
  exit()
a=1
t=7
m=0
while 1:
  t=t*10%k
  m+=t
  if m%k: a+=1
  else: break
print(a)