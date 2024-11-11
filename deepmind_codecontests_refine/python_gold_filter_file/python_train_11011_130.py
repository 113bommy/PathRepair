n,k=map(int,input().split())
a=list(map(int,input().split()))
for _ in range(min(k,int(n**0.5)+10)):
  add_a=[0]*(n+1)
  for i in range(n):
    a[i]
    add_a[max(0,i-a[i])]+=1
    add_a[min(n,i+a[i]+1)]-=1
  tmp=0
  for i in range(n):
    tmp+=add_a[i]
    a[i]=tmp
print(' '.join(map(str,a)))
