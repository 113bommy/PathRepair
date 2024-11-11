n=int(input())
i=int(n**0.5)//2
while(i*(i+1)//2<n):
  i+=1
print(i)