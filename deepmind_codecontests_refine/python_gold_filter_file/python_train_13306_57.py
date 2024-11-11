L=int(input())
n=L.bit_length()
if L==2**n:
  n+=1
path=[]
for i in range(1,n):
  path.append([i,i+1,0])
  path.append([i,i+1,2**(i-1)])
k=(L-1)-(2**(n-1)-1)
cur=2**(n-1)
while k>0:
  if k==1:
    kk=1
  else:
    kk=k.bit_length()
  path.append([kk,n,cur])
  cur+=2**(kk-1)
  k=L-cur
print(n,len(path))
for p in path:
  print(*p)