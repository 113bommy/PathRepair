n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]

ab=[[a[i],b[i]] for i in range(n)]
ab.sort(key=lambda x:x[1])

a=[ab[i][0] for i  in range(n)]
b=[ab[i][1] for i  in range(n)]

ai=[[a[i],i] for i in range(n)]
ai.sort(key=lambda x:x[0])

flag1=True
for i in range(n):
  if ai[i][0]>b[i]:
    flag1=False
    break
    
idx=ai[0][1]
cnt=0
while idx!=0:
  idx=ai[idx][1]
  cnt+=1

if cnt==n-1:
  flag2=False
  for i in range(n-1):
    if b[i]>=ai[i+1][0]:
      flag2=True
      break
else:
  flag2=True
  
if flag1 and flag2:
  ans='Yes'
else:
  ans='No'
print(ans)
  

