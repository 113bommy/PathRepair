n=int(input())
l=list(map(int,input().split()))
ans=1000
for i in l:
  t=0
  while(i%2==0):
    i=i//2
    t+=1
  ans=min(ans,t)
print(ans)