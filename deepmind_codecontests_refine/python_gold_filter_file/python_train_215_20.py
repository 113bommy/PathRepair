import statistics as stat
n,s=list(map(int,input().split()))
arr = list(map(int,input().split()))
arr.sort()
median = stat.median(arr)
index = arr.index(median)
cost=0;
if n==1:
  cost+=abs(s-median)
else:
  for x in arr[0:n//2+1]:
    if x>s:
      cost+=(x-s)
  for x in arr[n//2:len(arr)]:
    if x<s:
      cost+=(s-x)
print(cost)
