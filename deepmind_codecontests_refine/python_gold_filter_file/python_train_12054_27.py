a=int(input())
sum=0
for i in range(a+1):
  if i%3!=0 and i%5!=0:
    sum=sum+i
print(sum)