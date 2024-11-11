N, K = map(int, input().split())
As = list(map(int, input().split()))

for i in range(K, N):
  if As[i-K] < As[i]:
    print('Yes')
  else:
    print('No')