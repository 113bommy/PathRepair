
num = input()
grupos = input()
grupos = grupos.split()
taxis = 0
unos = 0
dos = 0
tres = 0

for g in grupos:
    g = int(g)
    if ( g == 4):
        taxis = taxis + 1
    elif (g == 3):
        tres = tres + 1
    elif (g == 2):
        dos = dos + 1
    elif(g == 1):
        unos = unos + 1

while(tres>0):
    if(unos>0):
        taxis = taxis + 1
        unos = unos - 1
        tres = tres - 1
    else:
        taxis = taxis + 1
        tres = tres - 1

while(dos>0):
    if(dos>=2):
        taxis = taxis + 1
        dos = dos - 2
    else:
        if(unos>=1):
            taxis = taxis + 1
            dos = dos - 1
            unos = unos - 2
        else:
            taxis = taxis + 1
            dos = dos - 1

while(unos>0):
    taxis = taxis + 1
    unos = unos - 4

print(taxis)

