n=int(input())
x=[int(n) for n in input().split()]
c=0
m=0
for i in range(1,n):
  if x[i-1]>=x[i]:
    c+=1
  else:
    c=0
  m=max(c,m)
print(m)