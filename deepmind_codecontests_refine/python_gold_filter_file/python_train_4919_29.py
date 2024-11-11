def answer(n, s):
  arr = ([1] * (n-1)) + [s-n+1]
  leftSum = sum(arr[:(n-1)])
  last = arr[-1]
  diff = last - leftSum
  if diff > 1:
    print("YES")
    print(" ".join([str(i) for i in arr]))
    print(leftSum+1)
  else:
    print("NO")
    
n, s = map(int, input().split())
answer(n, s)