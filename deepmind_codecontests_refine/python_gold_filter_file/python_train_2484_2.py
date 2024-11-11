n=int(input())
arr=[int(input()) for _ in range(n)]
ans=True
checked=[0]*n
num=0
for i in range(30,-1,-1):
  cnt=0
  pos=-1
  for j in range(n):
    if (arr[j])&(2**i)!=0:
      cnt+=1
      if arr[j]==2**i:
        pos=j
    arr[j]&=2**i-1
  if i!=0:
    if cnt%2==0:
      continue
    else:
      if pos==-1:
        ans=False
        break
      else:
        arr[pos]=2**i-1
        checked[pos]=1
        num+=1
        continue
  if i==0:
    if cnt%2==0:
      continue
    else:
      for j in range(n):
        if checked[j]==0:
          arr[j]-=1
          num+=1
          break
      else:
        ans=False
if ans==True:
  print(num)
else:
  print(-1)
