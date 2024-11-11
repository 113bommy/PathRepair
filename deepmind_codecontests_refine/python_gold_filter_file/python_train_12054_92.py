n=int(input())
a=0
for i in range(1,n+1):
  if i%5!=0 and i%3!=0:
    a=a+i
print(a)
