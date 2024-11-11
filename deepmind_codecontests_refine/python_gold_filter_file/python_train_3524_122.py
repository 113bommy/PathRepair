n=int(input())
j=1
for i in range(1,n+1):
  j=(j*i)%(10**9+7)
print(j)