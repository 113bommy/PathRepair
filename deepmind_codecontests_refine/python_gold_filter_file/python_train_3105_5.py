N=int(input())
a=[]
a=input().split()
sum=0
 
for i in range (1,N):
  if a[i-1]==a[i]:
    a[i]=i+10001
    sum=sum+1
 
print(sum)