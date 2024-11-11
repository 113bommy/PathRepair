Lights = input()
Pereg = [0] * 4

for i in range(0, len(Lights), 4):
    MasProm = Lights[i:i+4]
    kol = MasProm.count("!")
    if not kol:
        pass
    else:
        Lena = len(MasProm)
        if Lena == 4:
            if "R" not in MasProm:
                Pereg[0] += 1
            if "B" not in MasProm:
                Pereg[1] += 1
            if "Y" not in MasProm:
                Pereg[2] += 1       
            if "G" not in MasProm:
                Pereg[3] += 1
        else:
            Lamp = [""] * Lena
            for k in range(Lena):
                if MasProm[k] == "!":
                    for j in range(k%4, len(Lights), 4):
                        if Lights[j] != "!":
                            Lamp[k] = Lights[j]
            
            for k in range(Lena):
                if MasProm[k] == "!":
                    if Lamp[k] == "R":
                        Pereg[0] += 1
                    elif Lamp[k] == "B":
                        Pereg[1] += 1
                    elif Lamp[k] == "Y":
                        Pereg[2] += 1
                    elif Lamp[k] == "G":
                        Pereg[3] += 1
                
                    
    
print(" ".join(map(str, Pereg)))
