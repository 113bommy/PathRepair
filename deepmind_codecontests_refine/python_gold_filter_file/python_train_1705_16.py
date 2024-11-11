a=list(map(int, input().split()))
a.sort()
m=a[0]
n=a[1]
print(m+1)
for i in range(m+1):
  print(m-i,i)    
 