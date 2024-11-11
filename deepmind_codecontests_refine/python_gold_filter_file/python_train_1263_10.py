b, k = map(int, input().split())
arr = list(map(int, input().split()))
rem = arr[-1] % 2
for i in range(0, len(arr)-1):
  rem += (arr[i]%2)*(b%2)
if rem % 2 == 0:
  print("even")
else:
  print("odd")
