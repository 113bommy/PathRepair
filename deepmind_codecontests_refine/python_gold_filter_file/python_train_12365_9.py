N, K = map(int, input().split())
a = list(map(int, input().split()))

for i in range(K, N):
  if a[i] > a[i-K]:
    print("Yes")
  else:
    print("No")