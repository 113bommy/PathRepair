n=int(input())
a=input().split()
b=input().split()
c=input().split()
ans=0

for x in range(len(b)):
  ans+=int(b[x])
  if x+1<len(b):
    if int(a[x])+1==int(a[x+1]):
      ans+=int(c[int(a[x])-1])
print(ans)

