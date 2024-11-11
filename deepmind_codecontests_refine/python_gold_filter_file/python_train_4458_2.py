a=0
for i in range(int(input())):
  b=input().split()
  if b[1]=='JPY':
    a+=eval(b[0])
  else:
    a+=eval(b[0])*380000
print(a)