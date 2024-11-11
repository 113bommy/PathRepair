n=int(input())
b=0
for i in range(1,int(n**0.5)+1):
  if n%i==0:
    b=i
    
print(b+n//b-2)