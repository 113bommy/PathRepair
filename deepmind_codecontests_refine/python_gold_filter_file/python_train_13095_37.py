X=int(input())
Y = input()
r=""
a=0
for i in Y:
  if r!=i:
    r=i
    a+=1
print(a)