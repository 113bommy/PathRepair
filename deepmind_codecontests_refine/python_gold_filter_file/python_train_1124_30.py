N,M=map(int,input().split())
a = "a"+input()+"q"
k = []
for i in range(M):
  ta,tb=map(str,input().split())
  k.append([ta,tb])
k = k[::-1]
s = 1
t = N
c=0
for i, j in k:
  if j == "R" and i == a[t]:
    t-=1
    c+=1
  if j == "L" and i == a[s]:
    s+=1
  if j == "R" and i == a[s-1] and s> 1:
    s-=1
  if j == "L" and i == a[t+1] and t< N:
    t+=1
  if s==t+1 and N!=0:break
if N>1:print(t-s+1)
else: 
  if s+c+1>1:print(1)
  else:print(0)
