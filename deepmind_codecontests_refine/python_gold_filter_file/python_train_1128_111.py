n=int(input())
a=list(map(int,input().split()))
b=[]
c=0
for i in range(n):
  if a[i]<3200:
    b.append(a[i]//400)
  else:
    c+=1
l=len(set(b))
print(max(1,l),l+c)