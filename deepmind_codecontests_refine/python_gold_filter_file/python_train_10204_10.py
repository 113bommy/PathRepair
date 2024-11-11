n=int(input())
a=input().split()
for i in range(n):
 k=int(a[i])
 j=i-1
 while j>=0 and int(a[j])>k:
  a[j+1]=a[j]
  j-=1
 a[j+1]=k
 print(*a)