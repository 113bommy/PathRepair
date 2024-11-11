n,k = map(int,input().split())
lis = list(map(int,input().split()))
for i in range(n-k):
  if lis[i] < lis[i+k]:
    print("Yes")
  else:
    print("No")
