n=int(input())
arr1=list(map(int,input().split()))
arr1=sorted(arr1)
m=int(input())
arr2=list(map(int,input().split()))
arr2=sorted(arr2)
pos=0
for i in range(n):
  if arr1[i]==arr2[pos]:
    pos+=1
  if pos==m:
    print('YES')
    break
else:
  print('NO')