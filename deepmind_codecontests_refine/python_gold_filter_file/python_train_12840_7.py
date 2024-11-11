def stripe(arr):
  s_1=0
  count=0
  sum_total=sum(arr)
  for i in range(len(arr)-1):
    s_1=s_1+arr[i]
    s_2=sum_total-s_1
    if(s_1==s_2):
      count=count+1
    else:
      continue
  return(count)
n=int(input())
arr=list(map(int,input().split()))
result=stripe(arr)
print(result)
