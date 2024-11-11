n=int(input())
k=1
for i in range(1,int(n**0.5)+1):
  if n%i==0:
    k=i
print(k-1+n//k-1)