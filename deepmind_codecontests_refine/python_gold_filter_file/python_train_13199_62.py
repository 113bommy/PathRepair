a=int(input())
for x in range(int(a**0.5),0,-1):
  if a%x==0:
    b=int(a//x)
    break
print(b+x-2)