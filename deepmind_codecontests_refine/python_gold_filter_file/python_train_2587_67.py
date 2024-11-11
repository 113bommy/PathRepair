a,b=input().split()
a=int(a)
b=int(b)
c=0
for i in range(a+1):
  for k in range(a+1):
    if b-a<=i+k<=b:
      c=c+1
print(c)