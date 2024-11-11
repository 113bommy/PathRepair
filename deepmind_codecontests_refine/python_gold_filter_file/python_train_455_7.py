secuencia = input()
plus = secuencia.count("+")
minus =secuencia.count("-")

if len(secuencia)%2==0:
    if (secuencia == secuencia[::-1]):
        print("Yes")
    else:
        if plus%2 ==0 and minus%2==0:
            largo = len(secuencia)//2
            if "++" in secuencia or "--" in secuencia:
                for i in range(0,largo):
                    #print(secuencia)
                    try:
                        secuencia = secuencia.replace("++","")
                        secuencia = secuencia.replace("--","")
                        #print(secuencia)
                        continue
                    except:
                        continue
            if secuencia=="":
                print("Yes")
            else:
                print("No")
        else:
            print("No")
    
else:

    print("No")

