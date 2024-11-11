numero=int(input())
a=1000
while numero%a != 0:
  a-=1
print(a)
print((str(numero//a) + " ") * a)