mesa = input()
cartas = input().split(" ")
mesaChar = list(mesa)
rta = "NO"
for carta in cartas:
    cartaChar = list(carta)
    if cartaChar[0] == mesaChar[0] or cartaChar[1] == mesaChar[1]:
        rta = "YES"
        break
print(rta)