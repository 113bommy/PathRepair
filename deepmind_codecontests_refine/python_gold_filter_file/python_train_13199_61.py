tall = int(input())
bit = int(tall**(1/2))
while ((tall/bit)%1 != 0):
  bit -= 1
print(int(bit+tall/bit-2))