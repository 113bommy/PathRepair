from math import fabs
arr=list(map(int,input().split()))
arr.sort()
if arr[2]>=arr[1]+arr[0]:
  
  print(int((fabs(arr[2]-(arr[0]+arr[1]))+1)))

else:
  print(0)
