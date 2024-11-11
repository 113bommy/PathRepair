def stack(days,count):
  x=count//days
  y=count%days
  return days*(x)*(x-1)//2+y*x
def func(arr,days):
  total=0
  for x in range(len(arr)):
    if arr[x]<=(x)//days:
      break
    else:
      total+=arr[x]-(x)//days
  return total
def main():
  arr=input().split()
  n=int(arr[0])
  pages=int(arr[1])
  arr=input().split()
  for x in range(n):
    arr[x]=int(arr[x])
  arr.sort(reverse=True)
  
  lower=1
  upper=4*10**5
  while upper-lower>1:
    mid=(upper+lower)//2
    total=func(arr,mid)
    if total>=pages:
      upper=mid
    else:
      lower=mid

  if func(arr,lower)>=pages:
    return lower
  elif func(arr,upper)>=pages:
    return upper
  else:
    return -1


print(main())
