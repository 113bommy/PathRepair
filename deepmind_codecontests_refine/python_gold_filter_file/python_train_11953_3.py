n=int(input())
a=input()
b=input()
c=input()
ans=0
for i in range(n):
  m=len(set([a[i],b[i],c[i]]))
  ans+=m-1
print(ans)
