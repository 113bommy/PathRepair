N, x=map(int, input().split())
a=list(map(int, input().split()))
a.sort()
i=0
while i<N and x>=a[i]:
  x-=a[i]
  i+=1
if i==N and x>0:
  i-=1
print(i)