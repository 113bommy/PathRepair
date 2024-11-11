n, k = [int(i) for i in input().strip().split()]
arr = [int(i) for i in input().strip().split()]
if max(arr) - min(arr) > k:
  print('NO')
else:
  print('YES')
  for i in arr:
    print(*[j%k + 1 for j in range(i)])