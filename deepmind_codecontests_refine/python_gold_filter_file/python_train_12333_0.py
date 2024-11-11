n,r,avg=map(int,input().split())
arr=[]
summ=0
for i in range(n):
  a,b=map(int,input().split())
  summ+=a
  arr.append([a,b])
need=(n*avg)-summ
#print(need)
if need==0:
  print(0)
else:
  ans=0
  arr=sorted(arr,key=lambda x:x[1])
  for i in range(n):
    if arr[i][0]<r and need>0:
      add=r-arr[i][0]
      if need>=add:
        need-=(add)
      else:
        m=add-need
        add-=m
        need-=add
     # print(ans)
      ans+=(add*arr[i][1])
    if need==0:
        break
  print(ans)
 

