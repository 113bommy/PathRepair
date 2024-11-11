n=int(input())
arr=list(map(int,input().split()))
arr.sort()
s=0
for i in range(0,(2*n)-1,2):
  s+=arr[i]
print(s)