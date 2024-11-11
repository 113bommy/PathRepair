N,K=map(int,input().split())
alist=list(map(int,input().split()))

for i in range(K,N):
  if alist[i]>alist[i-K]:
    print("Yes")
  else:
    print("No")