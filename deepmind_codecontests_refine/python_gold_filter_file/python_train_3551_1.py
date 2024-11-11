n=int(input())
ans=[]
curr=1
while curr<=n:
  for _ in range(n//curr-n//(2*curr)):
    ans.append(curr)
  if n<2*curr:
    break
  tmp=2
  while n//(tmp*curr)==n//((tmp+1)*curr):
    tmp+=1
  curr*=tmp
print(' '.join(map(str,ans)))