n,k = map(int,input().split())
v = list(map(int,input().split()))

m=[]
for i in range(k+1):
 for j in range(min(k,n)-i+1):
  # print(i,j)
  t=sorted(v[:i]+v[:~j:-1])
  while t and(k-i-j)*t[0]<0:t.pop(0);j+=1
  m+=sum(t),
print(max(m))
