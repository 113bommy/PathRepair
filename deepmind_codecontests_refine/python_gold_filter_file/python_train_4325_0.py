lectura = input()
sufix = set()
comb = {(len(lectura), 2)}
setPrueba = set()
while comb:
    x, y = comb.pop()
    pos3 = x + y
    for i in [y, 5 - y]:
        posIni = x - i
        stringActual = (posIni, i)
        if ( stringActual in setPrueba or (posIni < 5) or (lectura[posIni:x] == lectura[x:pos3]) ):
            #print("encontrado en el set")
            continue
        else:
            sufix.add(lectura[posIni:x])
            comb.add(stringActual)
            setPrueba.add(stringActual)
conclusion = sorted(sufix)
print(len(sufix))
for i in range(0,len(conclusion)):
    print(conclusion[i])