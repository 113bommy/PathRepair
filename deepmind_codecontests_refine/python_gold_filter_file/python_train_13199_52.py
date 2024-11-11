n=int(input())
p=1
for i in range(2,int(n**0.5)+1):
  if n%i==0:
    p=i
print(p+n//p-2)