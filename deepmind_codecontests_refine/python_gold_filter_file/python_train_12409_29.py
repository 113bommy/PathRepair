num = input().split()
l = int(num[0])
r = int(num[1])
num = -1

def digitos_diferentes(cadena):
    for i in cadena:
        if cadena.count(i) != 1:
            return False
    return True
if l == r and digitos_diferentes(str(l)):
    num = l

while l != r + 1:
    cadena = str(l)
    if digitos_diferentes(cadena):
        num = cadena
        break
    l += 1

print(num)