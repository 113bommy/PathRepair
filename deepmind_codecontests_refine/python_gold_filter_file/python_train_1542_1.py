n,a,d,l=int(input()),list(map(int,input().split())),set(),0;b=[0]*n
for i in range(n-1,-1,-1):
  c=0
  for j in range(2*i+1,n,i+1):c=(c+b[j])%2
  if a[i]!=c:b[i]+=1;d.add(i+1);l+=1
print(l)
print(*[d.pop()for _ in range(l)])