linea_ingresada = input()

zurdos,derechos,ambidiestros = linea_ingresada.split(' ')

zurdos = int(zurdos)
derechos= int(derechos)
ambidiestros = int(ambidiestros)

if zurdos > derechos:
    diferencia = zurdos - derechos
    if diferencia >= ambidiestros:
        resultado = derechos + ambidiestros
    else:
        resultado = zurdos + (ambidiestros - diferencia) / 2
else:
    if derechos > zurdos:
        diferencia = derechos - zurdos
        if diferencia >= ambidiestros:
            resultado = zurdos + ambidiestros
        else:
            resultado = derechos + (ambidiestros - diferencia) / 2
    else:
        resultado = zurdos + ambidiestros / 2

print(int(resultado) * 2)