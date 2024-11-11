N,K=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]

for x in range(K,N):
  if a[x]>a[x-K]:
    print("Yes")
  else:
    print("No")