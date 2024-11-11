import sys
k=int(input())
a=list(map(int,input().split()))
min=2;max=2
min=((min+a[k-1]-1)//a[k-1])*a[k-1]
max=(max//a[k-1])*a[k-1]
if min>max:
  print(-1)
  sys.exit()
for i in range(k-1,0,-1):
  max=max+a[i]-1
  min=((min+a[i-1]-1)//a[i-1])*a[i-1]
  max=(max//a[i-1])*a[i-1]
  if min>max:
    print(-1)
    sys.exit()
max+=a[0]-1
print(min,max)