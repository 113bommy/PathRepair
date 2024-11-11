n,l=map(int,input().split())
a=0
b=1000
for i in range(l,l+n):
  a+=i
  if abs(b)>abs(i):
    b=i
print(a-b)