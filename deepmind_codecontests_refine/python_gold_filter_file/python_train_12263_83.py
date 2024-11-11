a=int(input())
b=0
for i in range(a+1):
  c=i
  c+=(i*8)//100
  if c==a:
    b=i
print(":("if b==0 else b)