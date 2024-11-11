n=int(input())
arr=list(map(int,input().split()))
tmp=1
for i in range(n):
  if arr[i]%2==0:
    tmp*=2
print(3**n-tmp)