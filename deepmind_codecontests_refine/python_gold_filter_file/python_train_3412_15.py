K=int(input())
cnt=0
ans=0
while cnt<1000001:
  cnt+=1
  ans=(ans*10+7)%K
  if ans==0:
    print(cnt)
    break
else:
  print(-1)