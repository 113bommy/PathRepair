k=int(input())
 
ans=-1
init=7
for i in range(k+1):
  if init%k ==0:
    ans=i+1
    break
  init = (init*10+7)%k
print(ans)