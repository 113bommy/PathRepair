n, k = map(int,input().split())
a=0
for i in range(1,n+1):
  a+=max(0,i-k)*(n//i)+max(0,n%i-k+1)
if k==0:
  a-=n
print(a)
