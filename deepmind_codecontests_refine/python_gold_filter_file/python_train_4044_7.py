n=int(input())
a=2
b=1
for i in range(0,n):
  a,b=b,(a+b)
print(a)