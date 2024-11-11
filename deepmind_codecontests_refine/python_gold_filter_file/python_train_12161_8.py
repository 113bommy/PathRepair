a,s,d=map(int,input().split())
lis=list(map(int,input().split()))
c=0
for i in range(a):
  l=list(map(int,input().split()))    
  sum=d
  for k in range(s):
    sum+=lis[k]*l[k]
  if sum>0:
    c+=1
print(c)