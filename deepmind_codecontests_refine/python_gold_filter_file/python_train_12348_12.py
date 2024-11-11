n = int(input())
arr = list(map(int,input().split()))
arr.sort()
if arr[n-1] == arr[n]:
  print("NO")
else:
  print("YES")