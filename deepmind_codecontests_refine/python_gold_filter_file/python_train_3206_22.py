t,a,k = map(int,input().split())
 
t = t-k
if t<0:
  a += t
  t = 0
if a<0:
  a = 0
print(t,a)
