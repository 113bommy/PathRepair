n,c,k=map(int,input().split())
t=[0]*n
for i in range(n):
  t[i]=int(input())
t=sorted(t)

ans=1
cnt=0
time=t[0]+k

for i in range(n):
  if cnt==c or time<t[i]:
    cnt=1
    ans+=1
    time=t[i]+k
  else:
    cnt+=1
    
print(ans)