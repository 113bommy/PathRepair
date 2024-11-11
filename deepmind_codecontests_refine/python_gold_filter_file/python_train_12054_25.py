a=int(input())
b=0
for i in range(a+1):
  if i%3!=0 and i%5!=0:
    b=b+i
print(b)