numero = input()
if int(numero) > 9:
  a = ""
  i = 1
  aux = 9
  while True:
    if i > len(numero)-1:
      break
    if i == len(numero)-1:
      aux += (int(numero)-((10**i)-1))*(i+1)
    if i < len(numero)-1:
      aux+= ((10**(i+1)) - ((10**i))) * (i+1)
    i+=1
else:
  aux = int(numero)
  i = 0

print (aux)