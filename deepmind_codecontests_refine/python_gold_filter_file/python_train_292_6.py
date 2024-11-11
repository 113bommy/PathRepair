n=int(input())
l=list(map(int,input().split()))
c=0
for i in range(n-1):
  if l[i]==i+1:
    c+=1
    l[i],l[i+1]=l[i+1],l[i]
if l[n-1]==n:
  c+=1
print(c)