n=int(input())
a=list(map(int,input().split()))
m=0
for i in range(n):
  while a[i]%2==0:
    a[i]=a[i]//2
    m+=1
print(m)

  
